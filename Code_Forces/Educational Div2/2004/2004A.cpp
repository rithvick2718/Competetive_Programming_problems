#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n; //n>=2
        if(n>2){
            cout<<"NO\n";
            int h;
            while(n--)
            {
                cin>>h;
            }
        }
        else
        {
            int h1,h2;
            cin>>h1>>h2;
            if(abs(h1-h2)>1) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}