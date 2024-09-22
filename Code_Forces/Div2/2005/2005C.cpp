#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n, m;
    map<char, int> mp;
    mp['n'] = 0;
    mp['a'] = 1;
    mp['r'] = 2;
    mp['e'] = 3;
    mp['k'] = 4;
    while (t--) 
    {
        cin>>n>>m; //getting n,m
        vector<string> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        } //getting strings
        // Initialize DP table
        int dp[n + 1][5] = {}; //fine
        for (int j = 0; j < 5; j++) { //used for dp[n-1][j]
            int key = j;
            int c = 0;
            int s = 0;
            for (int k = 0; k < m; k++) {
                if (mp.find(w[n - 1][k]) != mp.end()) {
                    if (mp[w[n - 1][k]] == key) {
                        key++;
                        if (key > 4) {
                            s += 5;
                            key = 0;
                        }
                    } else {
                        c++;
                    }
                }
            }
            dp[n - 1][j] = max(dp[n][j], s - c - key);
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 5; j++) { //used for dp[n-i][j]
                int key = j;
                int c = 0;
                int s = 0;
                for (int k = 0; k < m; k++) {
                    if (mp.find(w[n - i][k]) != mp.end()) {
                        if (mp[w[n - i][k]] == key) {
                            key++;
                            if (key > 4) {
                                s += 5;
                                key = 0;
                            }
                        } else {
                            c++;
                        }
                    }
                }
                dp[n - i][j] = max(dp[n - i + 1][j], s - c + dp[n - i + 1][key]);
            }
        }
        cout << dp[0][0] << "\n";
    }
    return 0;
}