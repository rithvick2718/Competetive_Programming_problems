#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(a==0) return b;
    if(b==0) return a;
    int r = a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
vector<int> MakeB(vector<int> &a)
{
    int size =a.size();
    vector<int> b (size-1);
    for(int i=0; i<size-1; i++)
    {
        b[i]=gcd(a[i],a[i+1]);
    }
    return b;
}
void debug( vector<int> &a)
{
    for(int z : a)
    {
        cout<<z<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int copy =t;
    while(t--)
    {
        cout<<"Testcase : "<<copy-t<<"\n";
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        debug(a);
        vector<int> b =MakeB(a);
        debug(b);
        vector<int> count;
        for(int i =0; i< n-2; i++)
        {
            if(b[i]>b[i+1]) count.push_back(i);
        }
        if(count.size()>1) cout<<"NO\n";
        else if(count.size()==1)
        {
            if(gcd(a[count[0]],a[count[0]+2])<= b[count[0]+1]) cout<<"1YES\n";
            else cout<<"1NO\n";
        }
        else cout<<"-1YES\n";
    }
}