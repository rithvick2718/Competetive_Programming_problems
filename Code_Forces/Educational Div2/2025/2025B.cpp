#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long powerMod(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod;  // Square the base
        exp /= 2;      // Divide the exponent by 2
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n[t];
    int k[t];
    for(int i=0; i<t; i++)
    {
        cin>>n[i];
    }
    for(int i=0; i<t; i++)
    {
        cin>>k[i];
    }
    for(int i=0; i<t; i++)
    {
        if(n[i]==k[i]) cout<<1<<"\n";
        else cout<<powerMod(2LL,k[i])<<"\n";
    }
}