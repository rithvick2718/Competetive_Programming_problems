#include <bits/stdc++.h>
using namespace std;
int solve(int &a, int &b, int & l)
{
    set<int> ans;
    ans.insert(l);
    int copy =l;
    while(copy%b==0)
    {
        copy/=b;
        ans.insert(copy);
    }
    while(l%a==0)
    {
        l/=a;
        ans.insert(l);
        copy =l;
        while(copy%b==0)
        {
            copy/=b;
            ans.insert(copy);
        }
    }
    return ans.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; // Test cases
    cin >> t;
    int a, b, l; // The parameters in question 
    while (t--) {
        cin >> a >> b >> l; // a and b are guaranteed to be >2
        cout << solve(a,b,l) << "\n";
    }
    return 0; // Added return statement for main
}