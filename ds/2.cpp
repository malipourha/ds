#include <iostream>
#include <vector>
#include <queue>

std::vector<int> mergeSortedArrays(std::vector<std::vector<int>>& arrays) {
    std::priority_queue<std::pair<int, std::pair<int, int>>> min_heap;

    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            min_heap.push({-arrays[i][0], {i, 0}});
        }
    }

    std::vector<int> result;

    while (!min_heap.empty()) {
        auto [val, indices] = min_heap.top();
        min_heap.pop();
        result.push_back(-val);

        int arr_idx = indices.first;
        int element_idx = indices.second;

        if (element_idx + 1 < arrays[arr_idx].size()) {
            min_heap.push({-arrays[arr_idx][element_idx + 1], {arr_idx, element_idx + 1}});
        }
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> arrays;
    for (int i = 0; i < n; ++i) {
        int size;
        std::cin >> size;
        std::vector<int> array(size);
        for (int j = 0; j < size; ++j) {
            std::cin >> array[j];
        }
        arrays.push_back(array);
    }

    std::vector<int> merged_array = mergeSortedArrays(arrays);

    for (int i = 0; i < merged_array.size(); ++i) {
        std::cout << merged_array[i];
        if (i < merged_array.size() - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}
