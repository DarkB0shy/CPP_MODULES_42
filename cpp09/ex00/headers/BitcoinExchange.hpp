#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <cstdlib>

#define WRONG_N_ARGS "Fatal error: this program needs to be run with one file as argument."
#define NO_FILE "Fatal error: could not open file."
#define EMPTY_FILE "Fatal error: file can not be empty."
#define WRONG_FIRST_LINE "Fatal error: first line of the file must be 'date | value'"

class BitcoinExchange {
    private:
        std::multimap<std::string, double> _data;                       // std::map does not allow duplicate values. It will try to replace them or fail the insertion.
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void parseFile(const std::string &filename);
        void printData() const;
        bool isValidDate(const std::string &date) const;
        bool isValidValue(double value) const;
        void findClosestLowerDate(const std::string &databaseFilename) const;
};

void std_errore(const std::string err);

#endif
