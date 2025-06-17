#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> buildPrefixSum(const vector<vector<bool>>& GRID) {
    int n = GRID.size();
    int m = GRID[0].size();
    vector<vector<int>> preSum(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            preSum[i][j] = GRID[i][j];
            if (i > 0) preSum[i][j] += preSum[i-1][j];
            if (j > 0) preSum[i][j] += preSum[i][j-1];
            if (i > 0 && j > 0) preSum[i][j] -= preSum[i-1][j-1];
        }
    }

    return preSum;
}
int TrueCount(const vector<vector<int>>& preSum, int r1, int c1, int r2, int c2) {
    int res = preSum[r2][c2];
    if (r1 > 0) res -= preSum[r1 - 1][c2];
    if (c1 > 0) res -= preSum[r2][c1 - 1];
    if (r1 > 0 && c1 > 0) res += preSum[r1 - 1][c1 - 1];
    return res;
}
tuple<int, int, int, int> getIntersectionBounds(int i, int j, int k, int n, int m) {
    int r1 = max(0, i - k);
    int c1 = max(0, j - k);
    int r2 = min(n - 1, i + k);
    int c2 = min(m - 1, j + k);
    return {r1, c1, r2, c2};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        k--;
        int total_gold = 0;
        char c;
        vector<vector<bool>> grid(n, vector<bool>(m, false));
        vector<pair<int, int>> em_ind;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c;
                if (c == 'g') {
                    grid[i][j] = true;
                    total_gold++;
                } else if (c == '.') {
                    em_ind.push_back({i, j});
                }
            }
        }
        vector<vector<int>> PreSum = buildPrefixSum(grid);
        int mn = INT_MAX;
        for (auto [i, j] : em_ind) {
            auto [r1, c1, r2, c2] = getIntersectionBounds(i, j, k, n, m);
            mn = min(mn, TrueCount(PreSum, r1, c1, r2, c2));
        }
        cout << max(0, total_gold - mn) << "\n";
    }
    return 0;
}