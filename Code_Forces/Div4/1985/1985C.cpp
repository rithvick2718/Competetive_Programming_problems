#include <bits/stdc++.h>
using namespace std;
int solve(vector<long long int> &arr) {
    int ans=0;
    long long int sum = 0;
    long long int m =-1;
    for(int i=0;i<arr.size();i++)
    {
        sum=sum+arr[i];
        m=max(m,arr[i]);
        if(sum == 2*m) ans++; 
    }
    return(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve(a) << "\n";
    }
    return 0;
}