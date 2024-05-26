#include<bits/stdc++.h>
using namespace std;
int iterpow(const int &n, const int &p) //this is fine
{
    int x=p; // for bit representation
    int y =n; // even powers of n
    int r=1; // actual value of n^p
    do
    {
        if(x%2==1)
        {
            r=r*y;
        }
        y=y*y;
        x=x/2;
    }while(x!=0);
    return(r);
}
int f(vector<int> a) //fine too
{
    int v =0;
    for(int i=0; i<a.size(); i++)
    {
        v=v+ iterpow(2, a[i]);
    }
    return(v);
}
vector<bool> finv (int n, int size) //this stores finv in boolean array fine
{
    vector<bool> ans;
    for (size_t i = 0; i < size; i++)
    {
        ans.push_back(n&1);
        n=n>>1;
    }
    return(ans);
}
bool check(int s, int v,int n) //fine, this checks if s satisfies the condition for each v
{
    int u=v&s;
    // u=((~u)|s)&((~s)|u);
    int k=0;
    while(n--)
    {
        if((bool)u&1) k++;
        u=u>>1;
    }
    return((bool)((v>>k)&1));
}
bool work (int s,vector<int>V, int size)//checks the condition for all the elements of array
{
    bool ans=true;
    for (size_t i = 0; i < V.size(); i++)
    {
        ans=ans && check(s,V[i],size);
        if(!ans) break;
    }
    return(ans);
}
int main()
{
    int n;
    cin>>n;
    vector<int>V; //creating vi's
    int m =iterpow(2,n)-1;
    int k;
    while(m--)
    {
        cin>>k;
        V.push_back(k);
    } //now we have vis, yes it is taking vectors
    for(int s=0; s<iterpow(2,n);s++)
    {
        if(work(s,V,n)) cout<<s<<"\n";
    }
    return(0);
}