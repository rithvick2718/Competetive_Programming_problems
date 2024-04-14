#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    //so I need to print counter examples
    if(n==1 || n ==2) cout<<-1;
    else
    {
        while(n--) cout<<n+1<<" ";
    }
}