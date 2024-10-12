#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long x;
    long long mx_sum=-1000000001LL;
    long long pre_sum=0;
    long long mn_sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        pre_sum+=x;
        mx_sum=max(mx_sum,pre_sum-mn_sum);
        mn_sum=min(mn_sum,pre_sum);
    }
    cout<<mx_sum;
}