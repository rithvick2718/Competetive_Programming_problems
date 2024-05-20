#include<bits/stdc++.h>
using namespace std;
vector<unsigned int> arr; //global variable
int bitwiseproduct(int l,int r)
{
    if(l==r)
    {
        return arr[l];
    }
    int mid = l+(r-l)/2;
    int m = bitwiseproduct(l,mid);
    int n = bitwiseproduct(mid+1,r);
    return(m|n);
} //I am sure O(log n) I do not see a way to improve this
bool check_fork (int k, int n)
{
    int m = bitwiseproduct(0,k-1);
    for (int i=1; i<n-k+1 ;i++)
    {
        if(m!=bitwiseproduct(i,i+k-1))
        return(false);
    }
    return(true);
} //looks good O(n-k) may be I can improve this?
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    while(t--) //the code for each test case
    {
        int n;
        cin>>n; //taking n
        int h; //to push numbers
        for(int i=0; i<n; i++)
        {
            cin>>h;
            arr.push_back(h);
        } //now we have the array and the 0's
        // now it is time to find k I use a binary implementation
        int key =1;
        while((!check_fork(key,n)) && key<n)
        {
            key=2*key;
        }
        int mini =max(1,key/2);
        int maxi =min(n,key);
        int mid;
        while(mini<maxi)
        {
            mid = mini + (maxi-mini)/2;
            if(check_fork(mid,n))
            maxi=mid;
            else
            mini=mid+1;
        }
        cout<<mini<<"\n";
        arr.clear(); //empty the array
    }
}