#include <bits/stdc++.h>
using namespace std;
// Computes the greatest common divisor of a and b
int gcd(int a, int b) {
    int r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

// Computes the power of n in m
int maxPower(int m, const int &n) {
    int ans = 0;
    if (n == 1) return 0;
    while (m % n == 0) {
        ans++;
        m = m / n;
    }
    return ans;
}
// The main solve function
int solve(int a, int b, int l) {
    if (a == b)
        return (maxPower(l, a)+1);
    int g = gcd(a, b); // We know a != b
    // if (g == 1){
    //     int X = maxPower(l, a);
    //     int Y = maxPower(l, b);
    //     return ((X + 1) * (Y + 1));
    // }
    int ans=0;
    int copy =l*a;
    int X =maxPower(l,a);
    for(int x=0;x<=X;x++)
    {
        copy=copy/a;
        ans= ans+1+maxPower(copy,b);
    }
    return(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; // Test cases
    cin >> t;
    int a, b, l; // The parameters in question 
    while (t--) {
        cin >> a >> b >> l; // a and b are guaranteed to be >2
        cout << solve(a, b, l) << "\n";
    }
    return 0; // Added return statement for main
}
