#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &A, int k, int x) //checks MEX is atleast x
{
    int no_of_working_subarrays=0;
    vector<bool> is_present(x,false);
    int store=0;
    for(int a : A) // this traverses the whole array
    {
        if(a<x && !is_present[a]){
            store++;
            is_present[a]=true;
        }
        if(store==x){ //we know x>0
            fill(is_present.begin(), is_present.end(), false); // reset
            no_of_working_subarrays++;
            store=0;//resets store
        }
        if(no_of_working_subarrays>=k) return true;
    }
    return no_of_working_subarrays>=k;
}
int bin_ser(vector<int> &a, int n, int k)
{
    int low=0,high=n;
    int mid =low+(high-low)/2;
    while(low<high)
    {
        if(check(a,k,mid)){
            low=mid+1;
        }
        else{
            high=mid;
        }
        mid =low+(high-low)/2;
    }
    if(check(a,k,low)) return low;
    return low-1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        cout<<bin_ser(a,n,k)<<"\n";
    }   
}