#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> grids(7, vector<bool>(7, true)); // true means free
string k;
int solve(int pos, int s1, int s2) {
    if (pos == 48 && s1 == 6 && s2 == 0) return 1;
    if ((s1 == 6 && s2 == 0) || pos == 48) return 0;  // End conditions
    if (s1 < 0 || s2 < 0 || s1 > 6 || s2 > 6) return 0;  // Out of bounds
    // Mark the current position as visited
    grids[s1][s2] = false;
    int ans = 0;
    if (k[pos] == 'D' || k[pos] == '?' ) {
        if (s1 + 1 <= 6 && grids[s1 + 1][s2]) 
            ans = solve(pos + 1, s1 + 1, s2);
    }
    if (k[pos] == 'U' || k[pos] == '?' ) {
        if (s1 - 1 >= 0 && grids[s1 - 1][s2]) 
            ans = solve(pos + 1, s1 - 1, s2);
    }
    if (k[pos] == 'L' || k[pos] == '?' ) {
        if (s2 - 1 >= 0 && grids[s1][s2 - 1]) 
            ans = solve(pos + 1, s1, s2 - 1);
    }
    if (k[pos] == 'R' || k[pos] == '?' ) {
        if (s2 + 1 <= 6 && grids[s1][s2 + 1]) 
            ans = solve(pos + 1, s1, s2 + 1);
    }
    // Unmark the current position as visited (backtracking)
    grids[s1][s2] = true;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    cout << solve(0, 0, 0) << endl;
}
