#include<iostream>
#include<cmath>
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
        cin>>n;
        if(n%2==1) cout<<-1<<"\n";
        else cout<<1<<" "<<(n>>1)<<"\n";
    }
}