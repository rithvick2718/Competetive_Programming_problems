#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool operation(vector<ll> &a) {
    int n = a.size();
    bool changed = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            ll todec = (a[i] - a[i + 1]) / 2 + (a[i] - a[i + 1]) % 2;
            a[i] -= todec;
            a[i + 1] += todec;
            changed = true;
        }
    }
    return changed;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; // test cases
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int max_pos = max_element(a.begin(), a.end()) - a.begin();
        int min_pos = min_element(a.begin(), a.end()) - a.begin();        
        while (a[max_pos] - a[min_pos] > 1 && operation(a)) {
            max_pos = max_element(a.begin(), a.end()) - a.begin();
            min_pos = min_element(a.begin(), a.end()) - a.begin();
        }
        cout << a[max_pos] - a[min_pos] << "\n";
    }
    return 0;
}