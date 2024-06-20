#include <iostream>

std::string removeStarAndFirstChar(const std::string& s) {
    std::string result = "";

    for (char ch : s) {
        if (ch == '*') {
            result = result.substr(0, result.length() - 1);
        } else {
            result += ch;
        }
    }

    return result;
}

int main() {
    std::string inputStr;
    
    std::cin >> inputStr;

    std::string outputStr = removeStarAndFirstChar(inputStr);
    std::cout << outputStr << std::endl;

    return 0;
}
