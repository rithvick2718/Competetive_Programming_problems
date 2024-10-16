#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int> s;
    s.push_back(x);
    for(int i=1; i<n; i++)
    {
        cin>>x;
        auto it = upper_bound(s.begin(),s.end(),x);
        if(it==s.end()) s.push_back(x);
        else
        {
            *it=x;
        }
    }
    cout<<s.size();
}