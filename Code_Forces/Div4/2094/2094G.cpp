#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll q,s,k;
        deque<ll> a;
        bool is_reverse=false;
        ll sum=0LL;
        ll rizz=0LL;
        cin>>q;
        while(q--){
            cin>>s;
            if(s==1LL){
                if(is_reverse){
                    rizz+=sum-((ll)a.size())*a.front();
                    int temp=a.front();
                    a.pop_front();
                    a.push_back(temp);
                }
                else{
                    rizz+=sum-((ll)a.size())*a.back();
                    int temp=a.back();
                    a.pop_back();
                    a.push_front(temp);
                }
            }
            else if(s==2LL){
                rizz=(a.size()+1)*sum-rizz;
                is_reverse=!is_reverse;
            }
            else if(s==3LL){
                cin>>k;
                sum+=k; // this stays the same
                if(is_reverse)
                    a.push_front(k);
                else
                    a.push_back(k);
                rizz+=((ll)(a.size()))*k;
            }
            else cout<<-1<<"\n";
            cout<<rizz<<"\n";
        }
    }
}