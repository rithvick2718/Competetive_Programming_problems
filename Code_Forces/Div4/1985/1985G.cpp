#include<bits/stdc++.h>
#define VMOD 1000000007
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    int L,R,k;
    while(t--)
    {
        cin>>L>>R>>k;
        int m = 1;
        while(k*m<10)
        {
            m++;
        }
        m--;
        cout<<(L)*(m+1)*(m+1)+R*(m+1)<<"\n";
    }
}