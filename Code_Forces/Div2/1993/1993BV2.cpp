#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long h; //help variable
        long long mx_odd=-1; //all the numbers are +ve
        vector<long long> even;
        for(int i=0; i<n; i++)
        {
            cin>>h;
            if(h&1) mx_odd=max(h,mx_odd);
            else even.push_back(h);
        }
        if(even.size()==0 || mx_odd==-1)
        {
            cout<<0<<"\n";
        }
        else
        {
            int ans=even.size();
            sort(even.begin(),even.end());
            int size=even.size();
            for(int i=0;i<size;i++)
            {
                if(mx_odd>even[i]) mx_odd+=even[i];
                else break;
            }
            if(mx_odd<even.back()) ans++;
            cout<<ans<<"\n";
        }
    }
}