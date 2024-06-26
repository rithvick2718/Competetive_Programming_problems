#include <bits/stdc++.h>
using namespace std;
long long int SOLVE(long long x, long long y, long long k) {
    long long help1 = x % y;
    help1 = y - help1;
    if (k < help1) {
        return x + k;
    }
    if (k == help1) {
        x += k;
        while (x % y == 0) {
            x /= y;
        }
        return x;
    }
    while (true) {
        long long help2 = help1;
        if (x == 1) {
            break;
        }
        if (k >= help2) {
            k -= help2;
            x += help2;
            while (x % y == 0) {
                x /= y;
            }
            help1 = y - x % y;
        } else {
            x += k;
            k = 0;
            break;
        }
    }
    if (k != 0) {
        return k % (y - 1) + 1;
    }
    return x;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        cout << SOLVE(x, y, k) << endl;
    }
    return 0;
}