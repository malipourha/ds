#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int index, value, q;
    std::cin >> index >> value >> q;
    
    std::vector<int> numbers;
    for (int i = 0; i < q; ++i) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }

    int had = 0;
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < q; ++j) {
            if (i != j) {
                if (std::abs(j - i) <= index && std::abs(numbers[j] - numbers[i]) <= value) {
                    had = 1;
                    break;
                }
            }
        }
        if (had == 1) {
            break;
        }
    }

    if (had == 1) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
