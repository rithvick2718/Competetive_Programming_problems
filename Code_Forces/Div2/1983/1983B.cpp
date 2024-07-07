#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));
        
        // Read grid a
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                a[i][j] = ch - '0';  // Convert char to int
            }
        }
        
        // Read grid b
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                b[i][j] = ch - '0';  // Convert char to int
            }
        }

        vector<int> rsuma(n, 0);
        vector<int> rsumb(n, 0);
        vector<int> csuma(m, 0);
        vector<int> csumb(m, 0);

        // Calculate row sums modulo 3
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rsuma[i] = (rsuma[i] + a[i][j]) % 3;
                rsumb[i] = (rsumb[i] + b[i][j]) % 3;
            }
        }

        // Calculate column sums modulo 3
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                csuma[j] = (csuma[j] + a[i][j]) % 3;
                csumb[j] = (csumb[j] + b[i][j]) % 3;
            }
        }

        bool ans = true;

        // Check row sums
        for(int i = 0; i < n && ans; i++) {
            if(rsuma[i] != rsumb[i]) {
                ans = false;
            }
        }

        // Check column sums
        for(int j = 0; j < m && ans; j++) {
            if(csuma[j] != csumb[j]) {
                ans = false;
            }
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
