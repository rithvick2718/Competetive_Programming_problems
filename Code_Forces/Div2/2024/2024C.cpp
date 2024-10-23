#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i].first >> nums[i].second;
        }
        sort(nums.begin(), nums.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first+a.second<b.second+b.first;
        });
        for (int i = 0; i < n; i++) {
            
            cout << nums[i].first << " " << nums[i].second << " ";
        }
        cout << "\n";
    }
    return 0;
}