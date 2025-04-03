#include<bits/stdc++.h>
using namespace std;
int cycle_replace(vector<pair<int,bool>> &arr, int d);
int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        //code
        int n;
        cin>>n;
        vector<pair<int,bool>> arr(n);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i].first;
            arr[i].second=false;
        }
        // cout<<cycle_replace(arr,2);
        int d;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            cin>>d;
            if(arr[d-1].second){
                //ntg
            }
            else
            {
                ans+=cycle_replace(arr,d);
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}
int cycle_replace(vector<pair<int,bool>> &arr, int d)
{
    int ans=0;
    int start=d-1;
    int next=arr[start].first-1;
    do
    {
        ans++;
        arr[start].first=start+1;
        arr[start].second=true;
        start=next;
        next=arr[start].first-1;
    } while (start!=d-1);
    return ans;
}