#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ans=0;
    int to_divide=5;
    while(n>=to_divide)
    {
        ans+=n/to_divide;
        to_divide*=5;
    }
    cout<<ans;
}