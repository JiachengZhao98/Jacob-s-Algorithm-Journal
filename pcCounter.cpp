#include <iostream>
#include <unordered_map>
#include <string>

void countPCOccurrences(std::istream& input, std::ostream& output) {
    std::unordered_map<std::string, int> pcCounts;
    std::string pc;
    while (getline(input, pc)) {
        pcCounts[pc]++;
    }

    for (const auto &entry : pcCounts) {
        output << "Program Counter: " << entry.first << ", Count: " << entry.second << std::endl;
    }
}
