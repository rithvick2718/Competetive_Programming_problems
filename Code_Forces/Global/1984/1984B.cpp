#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    long long int x;
    while (t--)
    {
        //code for each test case
        cin>>x; //take x
        if(x%10 == 9) cout<<"NO\n"; //last digit cannot be 9
        else
        {
            bool ans=true;
            x=x/10;
            while(x>9)
            {
                if(x%10==0)
                {
                    ans=false;
                    break;
                }
                x=x/10;
            }
            if(!ans) cout<<"NO\n";
            else
            {
                if(x==1) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
}