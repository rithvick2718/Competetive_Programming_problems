#include<bits/stdc++.h>
using namespace std;
template<int n>
int cal (int (&presolve)[n+1][32], int (&a)[n+1], int l, int r)
{
    //so this calculates for a[l]&a[l+1]&a[l+2]...&a[r]
    int ans = a[l];
    for(int j=0; j<32; j++)
    {
        if(a[r][j]-a[l-1][r]!=r-l) ans=ans &(~(1<<j));
    }
    return(ans);
}
// int binser(int (&presolve)[n+1][32], int (&a)[m+1], int l, int k)
// {
//     //this will be called only when we know arr[l]>k
//     // so we need to binary search for r
//     int low  =l;
//     int high =sizeof(a)/sizeof(a[0]);
//     int mid; //equal to (low+high)/2
//     while(low<high)
//     {
//         mid= low+(high-low)/2;
//         if(cal(presolve, a, l, mid) <k)
//             high=mid;
//         else
//         low =mid+1;
//     }
//     if(low <sizeof(a)/sizeof(a[0])) return(low);
//     else return(-1);
// }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //test cases
    cin>>t;
    while(t--)
    {
        int n; //size of array
        cin>>n;
        int a[n+1]; //a[0] is ignored
        a[0]=0;
        int presolve[n+1][32];
        fill(presolve,presolve+(n+1)*32,0); //fine
        int h;
        //input and presolve block
        for(int i=1; i<=n;i++) //fine
        {
            cin>>a[i];
            h=a[i];
            for(int j=0; h; j++)
            {
                if(h&1) presolve[i][j]=presolve[i-1][j]+1;
                else presolve[i][j]=presolve[i-1][j];
                h>>=1;
            }
        }
        int q,l,k;
        cin>>q;
        while(q--)
        {
            cin>>l>>k;
            l--;
            if(a[l]<k) cout<<"-1 ";
            else
            {
                //now I am supposed to apply binary search for r
                // cout<<binser(presolve,a,l,k)<<" ";
            }
            cout<<"\n";
        }
    }
}