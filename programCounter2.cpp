#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main() {
    std::string traceFilePath = "trace.txt"; // Replace with your trace file path
    std::ifstream traceFile(traceFilePath);
    std::unordered_map<std::string, int> pcCounts; // Map to store PC counts

    if (!traceFile.is_open()) {
        std::cerr << "Failed to open file: " << traceFilePath << std::endl;
        return 1;
    }

    std::string pc;
    while (getline(traceFile, pc)) {
        pcCounts[pc]++; // Increment the count for this PC
    }

    traceFile.close(); // Close the file

    // Output the counts for each program counter
    for (const auto &entry : pcCounts) {
        std::cout << "Program Counter: " << entry.first << ", Count: " << entry.second << std::endl;
    }

    return 0;
}
