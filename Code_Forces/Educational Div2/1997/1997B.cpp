#include <iostream>
#include<vector>
#include <cstddef>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(2);
        cin >> s[0] >> s[1];
        bool DOT = false;
        for (int i = 0; i < n; i++) {
            if (s[0][i] == '.' || s[1][i] == '.') {
                DOT = true;
                break;
            }
        }
        if (!DOT) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        int count[n + 2] = {0};
        int dot_count = 0;
        for (int i = 0; i < n; i++) {
            if (s[0][i] == '.') dot_count++;
            if (s[1][i] == '.') dot_count++;
            count[i] = dot_count;
        }
        for (int i = 1; i < n - 1; i++) {
            int left_dots = count[i - 1];
            int right_dots = count[n - 1] - left_dots - 2;
            if (s[0][i] == '.' && s[1][i - 1] == 'x' && s[1][i + 1] == 'x' && left_dots > 0 && right_dots > 0 && s[1][i] == '.') {
                ans++;
            }
            if (s[1][i] == '.' && s[0][i - 1] == 'x' && s[0][i + 1] == 'x' && left_dots > 0 && right_dots > 0 && s[0][i] == '.') {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}