#include<bits/stdc++.h>
using namespace std;
int no_of_prime_factors;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        //code
        int n,t;
        cin>>n;
        t=n;
        int a;
        map<int,int> m;
        while(t--){
            cin>>a;
            int i=3;
            while(a>1){
                while(a%2==0){
                    m[2]++;
                    a/=2;
                }
                while(a%i==0){
                    m[i]++;
                    a/=i;
                }
                i+=2;
                if(i>1000){ // we know that i<a until we encounter the last prime factor of a.
                    // a can have only one prime factor of size >1000
                    m[a]++;
                    break;
                }
            }
        }
        bool ans = true;
        for(auto val : m){
            if(val.second%n!=0){
                ans=false;
                break;
            }
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}