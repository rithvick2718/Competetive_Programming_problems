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
        int n; //W.L.O.G. let l>r
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        tuple<int,int, int> g={0,0,0}; //  (n,l,r) n = highest decrease in inversions and r is the value at which it occurs
        for(int l=0; l<n-1; l++)
        {
            int p=0,q=0;
            for(int r=l; r<n; r++)
            {
                if(a[r]<a[l]) p++;
                if(a[r]>a[l]) q++;
                if(p-q>get<0>(g)) g={p-q,l,r};
            }
        }
        cout<<get<1>(g)+1<<" "<<get<2>(g)+1<<"\n";
    }
}