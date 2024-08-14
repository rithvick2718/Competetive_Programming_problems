#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
long long caldiff(const vector<long long> &p, long long k, int n) {
    long long diff = 0;
    for (int i = 0; i < n; i++) 
    {
        if (k & 1) diff += p[i];
        else diff -= p[i];
        k >>= 1;
    }
    return abs(diff);
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);   
    int n;
    cin >> n;
    vector<long long> p(n);
    for (long long i = 0; i < n; i++) 
    {
        cin >> p[i];
    }
    long long j = (1 << n);
    long long mn = INT_MAX;
    for (long long i = 0; i < j; i++)
    {
        mn = min(mn, caldiff(p, i, n));
        if (mn == 0) break;
    }
    cout << mn << "\n";
    return 0;
}