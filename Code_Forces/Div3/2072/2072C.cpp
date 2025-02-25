#include<bits/stdc++.h>
using namespace std;
// std::string toBinary(int x) {
//     return std::bitset<32>(x).to_string(); // 32-bit representation
// }
int t_pwr(int x)
{
    int ans=1;
    while(x!=0){
        if(!(x&1)) return ans;
        else ans<<=1;
        x>>=1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //code
        int n,x;
        cin>>n>>x;
        int z = t_pwr(x);
        if(n>z) //clear
        {
            for(int i=0; i<z; i++) //upto z-1
            {
                cout<<i<<" ";
            }
            for(int i=z; i<n; i++) cout<<x<<" ";
            cout<<"\n";
        }
        else
        {
            for(int i=0; i<n-1; i++) cout<<i<<" ";
            if(n-1>(z>>1)-1 && x==z-1) cout<<n-1<<"\n";
            else cout<<x<<"\n";
        }
    }
}