#include<bits/stdc++.h>
using namespace std;
int pow(int a, int n)
{
    if(n==0) return(1);
    if(n%2==0) return(pow(a,n/2)*pow(a,n/2));
    else return(pow(a,(n-1)/2)*pow(a,(n-1)/2)*a);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr;
    for ( int i = 0; i < 10; i++)
    {
        arr.push_back(pow(2,i));
    }
    auto k =upper_bound(arr.begin(), arr.end(), 64);
    cout<<*k;
}