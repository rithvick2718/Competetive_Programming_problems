#include<bits/stdc++.h>
using namespace std;
bool isans(int a)
{
    vector<int> digits;
    while(a)
    {
        digits.push_back(a%10);
        a/=10;
    }
    int size=digits.size();
    if(size<3) return false;
    if(digits[size-1]==1 && digits[size-2]==0)
    {
        int sum =0;
        int to_multiply=1;
        for(int i=0; i<size-2; i++)
        {
            sum+=to_multiply*digits[i];
            to_multiply*=10;
        }
        if(sum<2) return false;
        else
        {
            if(digits[size-3]==0) return false;
            return true;
        }
    }
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int a;
    while(t--)
    {
        cin>>a;
        if(isans(a)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}