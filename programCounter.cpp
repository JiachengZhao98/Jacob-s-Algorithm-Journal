#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main(int argc, char* argv[]) {
    // Check if a file name is provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <trace_file>" << std::endl;
        return 1;
    }

    std::ifstream traceFile(argv[1]);
    if (!traceFile.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    }

    std::map<std::string, int> pcCounts;
    std::string pc;

    // Read the trace file line by line
    while (getline(traceFile, pc)) {
        // Increment the count for this PC
        ++pcCounts[pc];
    }

    traceFile.close();

    // Output the counts for each PC
    for (const auto& pair : pcCounts) {
        std::cout << "PC " << pair.first << " seen " << pair.second << " times" << std::endl;
    }

    return 0;
}
