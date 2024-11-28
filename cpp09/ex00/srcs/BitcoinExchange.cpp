#include "../headers/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {*this = other;}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _data.clear();
        _data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {_data.clear();}

void BitcoinExchange::parseFile(const std::string &filename) {
    std::ifstream file(filename.c_str());
    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (firstLine) {
            if (line != "date | value") std_errore(WRONG_FIRST_LINE);
            firstLine = false;
            continue;
        }
        if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
            std::string::size_type pos = date.find_last_not_of(" \t\n\r");                          // This only ignores whitespaces. std::string::size_type is used to store the position of a character within the string or to indicate the size of the string.
            if (pos != std::string::npos) {
                date.erase(pos + 1);
            }
            pos = date.find_first_not_of(" \t\n\r");
            if (pos != std::string::npos) {
                date.erase(0, pos);
            }
            pos = valueStr.find_last_not_of(" \t\n\r");
            if (pos != std::string::npos) {
                valueStr.erase(pos + 1);
            }
            pos = valueStr.find_first_not_of(" \t\n\r");
            if (pos != std::string::npos) {
                valueStr.erase(0, pos);
            }
            char *endPtr;
            double value = std::strtod(valueStr.c_str(), &endPtr);
            if (*endPtr != '\0') {
                std::cerr << "Error: Invalid number format in line => " << line << std::endl;
                continue;
            }
            if (!isValidDate(date)) {
                std::cerr << "Error: Invalid date format in line => " << line << std::endl;
                continue;
            }
            if (!isValidValue(value)) {
                std::cerr << "Error: Value out of range in line => " << line << std::endl;
                continue;
            }
            _data.insert(std::make_pair(date, value));
        } else std::cerr << "Error: Bad input => " << line << std::endl;
    }
}

void BitcoinExchange::printData() const {for (std::multimap<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it) {std::cout << it->first << " => " << it->second << std::endl;}}

bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12) return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0))) daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1]) return false;
    if (year <= 2009) {
        if (year == 2009 && month >= 1 && day >= 2) return true;
        return false;
    }
    if (year >= 2022) {
        if (year == 2022 && month <= 03 && day <= 29) return true;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(double value) const {return value >= 0.0 && value <= 1000.0;}

void BitcoinExchange::findClosestLowerDate(const std::string &databaseFilename) const {
    std::ifstream dbFile(databaseFilename.c_str());
    if (!dbFile.is_open()) std_errore(NO_FILE);
    std::cout << "BTC portfolio:" << std::endl;
    for (std::multimap<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
        std::string currentDate = it->first;
        std::string line;
        std::string closestDate;
        std::string closestLine;
        dbFile.clear();
        dbFile.seekg(0, std::ios::beg);
        while (std::getline(dbFile, line)) {
            std::istringstream iss(line);
            std::string dbDate;
            std::string dbValueStr;
            if (std::getline(iss, dbDate, ',') && std::getline(iss, dbValueStr)) {
                if (dbDate < currentDate) {
                    closestDate = dbDate;
                    closestLine = line;
                } else if (dbDate == currentDate) {
                    closestDate = dbDate;
                    closestLine = line;
                    break;
                }
            }
        }
        if (!closestLine.empty()) {
            double excVal = std::stod(closestLine.substr(11));
            double totalVal = excVal * it->second;
            std::cout << it->first <<", #btcs " << it->second << " | BTC exchange fee: " << excVal << " | BTC networth: " << totalVal << std::endl;
        } else std::cerr << "Error: No closest lower date found for " << currentDate << std::endl;
    }
}