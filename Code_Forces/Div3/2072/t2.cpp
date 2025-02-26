#include<bits/stdc++.h>
using namespace std;
void print_vector(vector<int> &a)
{
    for(auto x :a)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return;
}
int t_pwr(int n)
{
    int ans=1;
    while((ans<<1)<=n)
    {
        ans<<=1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k=5;
    vector<int> a[2];
    a[0].push_back(k);
    // cout<<"1 : ";
    print_vector(a[0]);
    for(int n=2; n<40; n++)
    {
        // cout<<bitset<8>(n).to_string()<<" : ";
        int i=(n+1)&1; //index of current vector to be written
        int j =(n)&1; // index of vector to derive from
        a[i].clear();
        a[i].push_back(k);
        for(int l=0; l<n-2; l++)
        {
            a[i].push_back(a[j][l]^a[j][l+1]);
        }
        a[i].push_back(k);
        print_vector(a[i]);
    }
}