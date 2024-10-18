#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n, input;
    cin >> x >> n;
    set<int> p;
    p.insert(0);
    p.insert(x);
    multiset<int> diff;
    diff.insert(x);
    for (int i = 0; i < n; i++) {
        cin >> input;
        auto it_mx = p.upper_bound(input);  // First element strictly greater than input
        auto it_mn = prev(it_mx);  // Element just before input
        diff.erase(diff.find(*it_mx - *it_mn));
        diff.insert(*it_mx - input);
        diff.insert(input - *it_mn);        
        p.insert(input);
        cout << *prev(diff.end()) << " ";
    }
}