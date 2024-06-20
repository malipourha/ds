#include <iostream>
#include <set>
#include <vector>

using namespace std;

string classify_array(const vector<int>& arr, int x) {
    set<int> distinct_elements;

    for (int num : arr) {
        distinct_elements.insert(num);
    }

    int distinct_count = distinct_elements.size();

    if (distinct_count == x) {
        return "Good";
    } else if (distinct_count < x) {
        return "Bad";
    } else {
        return "Average";
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, x;
        cin >> n >> x;

        vector<int> arr(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }

        string result = classify_array(arr, x);
        cout << result << endl;
    }

    return 0;
}
