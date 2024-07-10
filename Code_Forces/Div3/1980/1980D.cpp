#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)//fine
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
void TurnB(vector<int> &a)//fine
{
    int size =a.size();
    vector<int> b (size-1);
    for(int i=0; i<size-1; i++)
    {
        b[i]=gcd(a[i],a[i+1]);
    }
    a=b;
}
bool SOLVE(vector<int> &a, const int &n)
{
    bool ph1 = true;
    int i=0;
    for(; i<n-2 && ph1; i++)
    {
        ph1 = (gcd(a[i],a[i+1])<=gcd(a[i+1],a[i+2]));
    }
    if(ph1) return true;
    i--;
    vector<int> copy =a;
    copy.erase(copy.begin()+i);
    TurnB(copy);
    if(is_sorted(copy.begin(),copy.end())) return true;
    copy=a;
    copy.erase(copy.begin()+i+1);
    TurnB(copy);
    if(is_sorted(copy.begin(),copy.end())) return true;
    copy=a;
    copy.erase(copy.begin()+i+2);
    TurnB(copy);
    if(is_sorted(copy.begin(),copy.end())) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        if(SOLVE(a,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}