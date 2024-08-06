#include<bits/stdc++.h>
using namespace std;
bool is_win (int a[], int i, int j, int k, int l)
{
    int s1=0;
    int s2=0;
    if(a[i]>a[k]) s1++;
    else if( a[i] < a[k]) s2++;
    else
    {
        s1++;
        s2++;
    }
    if(a[j]>a[l]) s1++;
    else if( a[j] < a[l]) s2++;
    else
    {
        s1++;
        s2++;
    }
    return s1>s2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int a[4];
    int wins;
    while(t--)
    {
        //code
        wins =0;
        int sa,su;
        for(int i=0; i<4;i++)
        {
            cin>>a[i];
        }
        if(is_win(a,0,1,2,3)) wins++;
        if(is_win(a,0,1,3,2)) wins++;
        cout<<2*wins<<"\n";
    }
}