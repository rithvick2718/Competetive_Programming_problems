#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        k--; //now we have the proper index of k as the array we work is 0 indexed
        int a[n]; //initalize the array
        for(int x=0; x<n; x++)//get the array
        {
            cin>>a[x];
        }
        int i=0;
        for(; i<n; i++)
        {
            if(a[i]>a[k]) break;
        }// now we have 2 cases i<k or i>k
        int ans1 =i-1;
        if(i>k) cout<<ans1<<"\n"; //fine
        else
        {
            int j=i+1;
            for(; j<k; j++)
            {
                if(a[j]>a[k]) break;
            }
            int ans2=j-i-1+(i>0);
            cout<<max(ans1,ans2)<<"\n";
        }
    }
}