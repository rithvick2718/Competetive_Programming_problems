#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> a) {
    int size =a.size();
    if(size == 2) return(min(a[0],a[1]));
    int Max=-1;
    for(int i =0; i<a.size()-2; i++)
    {
        vector<int> t = {a[i],a[i+1],a[i+2]};
        sort(t.begin(),t.end());
        Max=max(Max, t[1]);
    }
    return(Max);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout<<solve(a)<<"\n";
    }
    return 0;
}