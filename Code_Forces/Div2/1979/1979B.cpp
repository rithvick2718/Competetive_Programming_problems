#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int x,y;
    while(t--)
    {
        cin>>x>>y;
        int k =x^y;
        int i=0;
        while(!(k&1))
        {
            i++;
            k=k>>1;
        }
        k =1<<i;
        cout<<k<<"\n";
    }
}