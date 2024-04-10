#include <fstream>
#include <vector>
#include <string>
#include "myVector.hpp"

int main() {
    std::ifstream file("testinput.txt");
    std::vector<int> instructions;
    std::string line;

    while (getline(file, line)) {
        if (line.substr(0, 6) == "insert") {
            instructions.push_back(stoi(line.substr(7)));
        } else if (line == "pop median") {
            instructions.push_back(-1);
        }
    }

    vectorMedian(&instructions);
    return 0;
}
