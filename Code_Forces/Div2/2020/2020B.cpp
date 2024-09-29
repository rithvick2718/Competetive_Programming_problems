#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool is_square(ll n) {
    ll root = sqrt(n);
    return root * root == n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    ll k;
    while(t--)
    {
        //code
        // if n is a square then it is 0, for non square it is 1
        cin>>k; // now we need n such that n - sqrt(n) = k
        double result = (1 + std::sqrt(1 + 4.0 * k)) / 2.0;
        ll ans = k+(ll)result;
        if(is_square(ans)) ans--;
        cout<<ans<<"\n";
    }
}