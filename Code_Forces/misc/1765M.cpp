#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=1;
        for(int i=2;i*i<=n;i++)
        {
            if((n-i)%i ==0){
                ans =max(ans,i);
                if((n-(n/i))%(n/i)==0) ans =max(ans,(n/i));
            }
        }
        cout<<ans<<" "<<n-ans<<"\n";
    }
}