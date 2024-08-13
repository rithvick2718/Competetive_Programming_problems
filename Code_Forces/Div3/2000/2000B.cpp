#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        bool ans = true;
        vector<bool> a(n, false);  // keeps track of occupied seats
        int h;
        cin >> h;
        a[h - 1] = true;  // mark the first occupied seat
        for (int i = 1; i < n; i++) 
        {
            cin >> h;
            if (h != 1 && h != n) {
                if (a[h - 2] || a[h]) {
                    ans = true;
                } else {
                    ans = false;
                }
            } else if (h == 1) {
                if (a[1]) {
                    ans = true;
                } else {
                    ans = false;
                }
            } else {  // h == n
                if (a[n - 2]) {
                    ans = true;
                } else {
                    ans = false;
                }
            }
            a[h - 1] = true; 
            if (!ans) {
                for (int j = i + 1; j < n; j++) {
                    cin >> h;  // consume the remaining input
                }
                break;  // exit the loop early
            }
        }

        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}