#include<bits/stdc++.h>
using namespace std; 
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
        if(n&1)
        {
            cout<<1<<" ";
            while(n>1){
                cout<<n<<" ";
                n--;
            }
            cout<<"\n";
        }
        else cout<<-1<<"\n";
    }
}