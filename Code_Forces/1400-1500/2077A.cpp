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
        int n;
        cin>>n;
        if(n>4){
            vector<ll> b(2*n);
            unordered_set<ll> s;
            for(int i=0; i<2*n; i++) {
                cin>>b[i];
                s.insert(b[i]);
            }
            sort(b.begin(),b.end());
            ll sum=0;
            for(int i=0; i<n; i++) sum+=b[i+n]-b[i];
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(s.count(abs(sum))==0 && sum!=0) break;
                    sum+=2*(b[j]-b[n+i]);
                    swap(b[n+i],b[j]);
                    if(s.count(abs(sum))==0 && sum!=0) break;
                }
                if(s.count(abs(sum))==0 && sum!=0) break;
            }
            if(sum>0){
                cout<<sum<<" ";
                for(int i=0; i<n; i++) cout<<b[n+i]<<" "<<b[i]<<" ";
                cout<<"\n";
            }
            else{
                cout<<-sum<<" ";
                for(int i=0; i<n; i++) cout<<b[i]<<" "<<b[n+i]<<" ";
                cout<<"\n";
            }
        }
        else {
        }
    }
}