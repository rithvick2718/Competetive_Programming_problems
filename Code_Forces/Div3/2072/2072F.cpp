#include<bits/stdc++.h>
using namespace std;
int t_pwr(int n)
{
    int ans=1;
    while((ans<<1)<=n)
    {
        ans<<=1;
    }
    return ans;
}
string build_it(int n, int k)
{
    string K=to_string(k);
    if (n==0) return "";
    if (n==1) return K +" ";
    if (n==2) return K +" "+ K +" ";
    int m =t_pwr(n);
    if(n==m) {
        string ans;
        for(int i=0; i<n; i++)
        {
            ans+=K+" ";
        }
        return ans;
    }
    string s =build_it(n-m,k);
    string zeros;
    for(int i=0; i<2*m-n; i++)
        {
            zeros+="0 ";
        }
    return s+zeros+s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,n,k;
    cin>>tt;
    while(tt--)
    {
        //code
        cin>>n>>k;
        cout<<build_it(n,k)<<"\n";
    }
}