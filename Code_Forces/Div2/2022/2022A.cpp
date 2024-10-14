#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //code
        int n,r,x;
        int happy=0;
        int left=0;
        cin>>n>>r;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            if(x&1){
                happy+=x-1;
                left++;
                r-=(x-1)/2;
            }
            else{
                happy+=x;
                r-=(x/2);
            }
        }
        if(left<=r){
            happy+=left;
        }
        else happy+=2*r-left;
        cout<<happy<<"\n";
    }
}