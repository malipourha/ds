#include <iostream>
#include <stack>

int calculate_score(const std::string& s) {
    std::stack<int> scoreStack;
    int score = 0;

    for (char ch : s) {
        if (ch == '(') {
            scoreStack.push(score);
            score = 0;
        } else if (ch == ')') {
            int poppedScore = scoreStack.top();
            scoreStack.pop();
            score = poppedScore + std::max(2 * score, 1);
        } else {
            std::cout << "Invalid character in the input string." << std::endl;
            return -1;  // خطا در صورت ورودی نامعتبر
        }
    }

    return score;
}

int main() {
    std::string input_str;
    std::cin >> input_str;

    int result = calculate_score(input_str);
    std::cout << result << std::endl;

    return 0;
}
