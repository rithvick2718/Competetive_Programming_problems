#include <iostream>
#include <vector>
using namespace std;

// Function to check if an array is non-decreasing
bool is_non_decreasing(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to check if the array can become non-decreasing after performing the operation
string can_become_non_decreasing(int n, vector<int>& arr) {
    // Check if the array is already non-decreasing
    if (is_non_decreasing(arr)) {
        return "Yes";
    }
    
    // Try all possible split points
    for (int i = 1; i < n; i++) {
        vector<int> new_arr(arr.begin() + i, arr.end());
        new_arr.insert(new_arr.end(), arr.begin(), arr.begin() + i);
        
        if (is_non_decreasing(new_arr)) {
            return "Yes";
        }
    }

    return "No";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << can_become_non_decreasing(n, arr) << endl;
    }
    return 0;
}