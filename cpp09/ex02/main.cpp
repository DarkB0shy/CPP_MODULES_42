// ./PMergeMe -657 -394 1204 507 990 -742 530 1412 -198 1346 -132 -596 633 600 -68 -1489 -1264 -1252 -1202 -515 1364 81 -461 -73 792 -1458 163 556 4 -967 357 1040 -480 -1057 -1322 -1034 -441 351 -1167 -44 -379 -1218 -1191 -1242 -625 -508 -48 988 -374 -955 -222 686 -82 101 -617 -1076 -327 -1325 -1025 585 916 845 -1340 -1243 -1099 154 602 -1195 -1234 1309 -1142 -1261 -220 1249 -946 627 -1228 -211 1310 -467 398 -256 122 1251 -1104 1406 1428 -1120 1397 708 862 -1304 1238 -1197 -1071 409 280 -483 601 -89 450 390 -1150 352 -1249 793 656 -659 -1266 473 -1477 358 461 -683 1263 1271 716 1194 -1111 -210 -1230 897 1102 1307 -1283 1111 1377 -1271 1398 -908 -1143 -1466 -301 395 -882 -1278 -842

#include "headers/PMergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <list>

int main(int argc, char *argv[]) {

    if (!argv[1]) {
        std::cerr << "Need a sequence of integers to run this program." << std::endl;
        exit(1);
    }

    std::cout << "Unsorted Array: ";


    std::vector<int> largeVector;
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num == 0 && std::string(argv[i]) != "0") {
            std::cerr << "Invalid integer." << std::endl;
            exit(2);
        }
        largeVector.push_back(num);
    }
    for (int i = 0; i < largeVector.size(); ++i) std::cout << largeVector[i] << " ";
    std::cout << std::endl;


    // std::vector<int> largeVector;
    // for (int i = -1500; i < 1500; ++i) {
    //     largeVector.push_back(i);
    // }
    // std::srand(static_cast<unsigned int>(std::time(0)));
    // for (size_t i = 0; i < largeVector.size(); ++i) {
    //     size_t j = i + std::rand() / ((RAND_MAX / (largeVector.size() - i)) + 1);
    //     std::swap(largeVector[i], largeVector[j]);
    //     std::cout << largeVector[i] << " ";
    // }
    // std::cout << std::endl;


    PMergeMe vectorSorter;
    double elapsedTimeVector = vectorSorter.measureSortingTime(largeVector, 1);
    std::cout << "Sorting an std::vector took " << elapsedTimeVector << " seconds." << std::endl;

    std::list<int> largeList(largeVector.begin(), largeVector.end());
    PMergeMe listSorter;
    double elapsedTimeList = listSorter.measureSortingTime(largeList, 0);
    std::cout << "Sorting an std::list took " << elapsedTimeList << " seconds." << std::endl;

    PMergeMe dequeSorter;
    std::deque<int> largeDeque(largeVector.begin(), largeVector.end());
    double elapsedTimeDeque = dequeSorter.measureSortingTime(largeDeque, 0);
    std::cout << "Sorting an std::deque took " << elapsedTimeDeque << " seconds." << std::endl;

    return 0;
}
