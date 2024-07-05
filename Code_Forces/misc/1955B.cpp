#include<bits/stdc++.h>
using namespace std;
bool find (multiset<int> &input, int &a11, int &n, int &c, int &d)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(input.count(a11+i*c+j*d)==0) return false;
            else input.erase(input.find(a11+i*c+j*d));
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,c,d;
    cin>>t;
    while (t--)
    {
        cin>>n>>c>>d;
        multiset<int> input;
        int help;
        int min = INT_MAX;
        for(int i=0; i<n*n; i++)
        {
            cin>>help;
            input.insert(help);
            if(help<min) min =help;
        } //see that the least value is a11
        if(find(input, min, n, c, d)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}