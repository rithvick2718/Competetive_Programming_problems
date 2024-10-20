#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        //code
        long long n;
        long long k;
        cin>>n>>k;
        long long a[n+1];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        if(a[0]*n>=k)
        {
            cout<<k<<"\n";
        }  
        else{
            long long store=k;
            k-=a[0]*n;
            long long size=n-1;
            long long i=1;
            while(k>0 && i<n)
            {
                if(k>(a[i]-a[i-1])*size){
                    k-=(a[i]-a[i-1])*size;
                    size--;
                    i++;
                }
                else break;
            }
            cout<<store+i<<"\n";
        }
    }
}