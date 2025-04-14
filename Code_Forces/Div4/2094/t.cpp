#include<bits/stdc++.h>
using namespace std;
vector<int> divisors(int k)
{
    if(k==1) return {};
    vector<int> v1,v2;
    for(int i=2; i*i<=k; i++)
    {
        if(k%i==0){
            v1.push_back(i);
            if(i!=k/i)v2.push_back(k/i);
        }
    }
    for(int i=v2.size()-1; i>=0; i--){
        v1.push_back(v2[i]);
    }
    v1.push_back(k);
    return v1;
} // O(srqt(k))
void print_v(vector<int> V)
{
    for(auto v : V) 
        cout<<v<<" ";
    cout<<"\n";
    return;
}
int reduce(int k, int d)
{
    if(d==0) return -1;
    if(d==1) return k;
    while(k%d==0) k/=d;
    return k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cout<<reduce(n,k)<<"\n";
    }
}