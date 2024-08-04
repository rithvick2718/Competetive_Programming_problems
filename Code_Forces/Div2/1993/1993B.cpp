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
        long long h;
        vector<long long> odd;
        vector<long long> even;
        for(int i=0; i<n; i++)
        {
            cin>>h;
            if(h&1) odd.push_back(h);
            else even.push_back(h);
        }
        if(even.size()==0 || odd.size()==0)
        {
            cout<<0<<"\n";
        }
        else
        {
            long long ans=0;
            sort(even.begin(),even.end());
            h=*max_element(odd.begin(),odd.end());
            for(auto it = even.begin(); it != even.end(); ++it)
            {
                long long e = *it;
                if(e < h)
                {
                    ans++;
                    h += e;
                }
                else
                {
                    ans += 2;
                    h += 2 * even.back();
                    if(it != even.end() - 1)
                    {
                        ans++;
                        h += e;
                        even.pop_back();
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
}