#include <bits/stdc++.h>
using namespace std;

int find_power(int n) {
    int ans = 0;
    while (n) {
        ans++;
        n /= 3;
    }
    return ans;
}

int iterpow(int n, int p) {
    int x = p;  // for bit representation
    int y = n;  // even powers of n
    int r = 1;  // actual value of n^p
    do {
        if (x % 2 == 1) {
            r = r * y;
        }
        y = y * y;
        x = x / 2;
    } while (x != 0);
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int ans = find_power(l);
        int curr_power = find_power(l);
        int threshold = iterpow(3, curr_power - 1);  // Starting threshold

        while (l <= r) {
            if (l < threshold * 3) {
                ans += curr_power;
            } else {
                curr_power++;
                threshold *= 3;
                ans += curr_power;
            }
            l++;
        }
        cout << ans << "\n";
    }
    return 0;
}
