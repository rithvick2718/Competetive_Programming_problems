#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char temp = '0';
        char h = '0';
        bool ans = true;
        
        while (n>0 && n--) {
            swap(h, temp);
            cin >> h;
            if ((h >= 'a' && h <= 'z') || (h >= '0' && h <= '9')) {
                if (h < temp) {
                    ans = false;
                     {
                        while (n>0 && n--) cin >> h;
                    }
                }
            } else {
                ans = false;
                 {
                    while (n>0 && n--) cin >> h;
                }
            }
        }
        
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}