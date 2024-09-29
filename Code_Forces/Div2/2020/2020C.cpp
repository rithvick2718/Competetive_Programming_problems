#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    ll b,c,d;
    ll B,C,D;
    while(t--)
    {
        //code
        cin>>b>>c>>d;
        B=b;
        C=c;
        D=d;
        ll a=0;
        int i=0;
        bool is_possible = true;
        while(b>0 || c> 0 || d > 0)
        {
            if(d&1LL){
                if(b&1LL && c&1LL){ // 1LL,1LL
                    //don't add anything to a
                }else if( b&1LL ){ // 1LL,0
                    // due to constraint don't add anything
                }else if(c&1LL){ //0,1LL
                    //we run into an issue here
                    a+=(1LL<<i);
                    d++;
                }
                else{
                    a+=(1LL<<i);
                }
            }else{ //fine!!
                if(b&1LL && c&1LL){ // 1LL,1LL
                    a+=(1LL<<i);
                }else if( b&1LL ){ // 1LL,0
                    is_possible=false;
                    break;
                }else if(c&1LL){ //0,1LL
                 // nothing 
                }
                else{
                    //nothing
                }
            }
            b>>=1LL;
            c>>=1LL;
            d>>=1LL;
            i++;
        }
         if((a|B)-(a&C)==D && a<=(1LL<<61))
         cout<<a<<"\n";
         else cout<<-1<<"\n";
    }
}