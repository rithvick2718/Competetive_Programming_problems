#include<bits/stdc++.h>
using namespace std;
bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        // If the first elements are equal, sort by the second element in increasing order
        return a.second < b.second;
    }
    // Otherwise, sort by the first element in non-decreasing order
    return a.first > b.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,n;
    cin>>tt;
    while(tt--)
    {
        //code
        cin>>n;
        vector<pair<int,int>> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i].first;
            a[i].second=i;
        }
        sort(a.begin(),a.end(),customComparator);
        int mn=INT_MAX;
        for(int i=0; i<n; i++)
        {
            mn=min(mn,a[i].second+i);
        }
        cout<<mn<<"\n";
    }
}