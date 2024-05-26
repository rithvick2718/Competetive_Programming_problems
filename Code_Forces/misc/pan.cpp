#include<iostream>
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
        if(n%2==1) cout<<3<<"\n";
        else cout<<2<<"\n";
    }
}