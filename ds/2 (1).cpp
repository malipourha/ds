#include <iostream>
#include <vector>
#include <algorithm>

std::string sort_groups(const std::string& input_str) {
    std::vector<std::string> groups;
    size_t start = 0;
    size_t end = input_str.find(' ');

    while (end != std::string::npos) {
        groups.push_back(input_str.substr(start, end - start));
        start = end + 1;
        end = input_str.find(' ', start);
    }

    groups.push_back(input_str.substr(start, end));

    std::sort(groups.begin(), groups.end(), [](const std::string& a, const std::string& b) {
        return a < b;
    });

    std::string result_str = "";
    for (const auto& group : groups) {
        result_str += group + "\n";  
    }

    return result_str;
}

int main() {
    int n;
    std::cin >> n;

    std::string input_line;
    std::getline(std::cin >> std::ws, input_line);

    std::string result = sort_groups(input_line);
    std::cout << result;

    return 0;
}
