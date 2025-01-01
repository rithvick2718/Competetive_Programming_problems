#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,input,blocks;
    cin>>t;
    while(t--)
    {
        cin>>n;
        blocks=0;
        bool was_last_0 =true;
        while(n--){
            cin>>input;
            if(was_last_0 && input!=0){
                blocks++;
                was_last_0=false;
            }
            else{
                if(input==0) was_last_0=true;
            }
        }
        if(blocks==0) cout<<0<<"\n";
        else if (blocks==1) cout<<1<<"\n";
        else cout<<2<<"\n";
    }
}