#include <iostream>
#include <vector>

std::vector<int> findGreaterDistances(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> distances;

    for (int i = 0; i < n; ++i) {
        int greaterDistance = 0;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[i]) {
                greaterDistance = j - i;
                break;
            }
        }
        distances.push_back(greaterDistance);
    }

    return distances;
}

int main() {
    int n;
    
    std::cin >> n;

    std::vector<int> elements(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i];
    }

    std::vector<int> result = findGreaterDistances(elements);

    
    for (int i : result) {
        std::cout << i << " ";
    }

    return 0;
}
