#include<bits/stdc++.h>
using namespace std;
int secondlargest(vector<int> arr) //find the second largest element of an array
{
    int size  = arr.size();
    int ans = INT_MIN;
    int m = arr[0];
    for(int i=0; i<size;i++)
    {
        if(arr[i]>m)
        {
            ans =m;
            m=arr[i];
        }
        else if( arr[i]>ans && arr[i]<m ) ans =arr[i];
    }
    return(ans);
}
int rmdfsa (int a[], int n) //remove duplicates from a sorted array
{
    int res=1;
    for(int i=0; i<n;i++)
    {
        if(a[i]!=a[res-1])
        {
            a[res]=a[i];
            res++;
        }
    }
    return(res);
}
int mzte(int arr[], int n) //move zeros to the end
{
    int nz=0;
    for(int i=0; i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[nz],arr[i]);
            nz++;
        }
    }
    return(nz);
}
void lrby1 (int arr[], int n) //left rotate by 1
{
    int hold =arr[0];
    for(int i=0; i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=hold;
}
// [START] Left rotate an array by D
void reverse (int arr[], int low, int high)
{
    while(low<high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}
void lrbyD (int arr[], int n , int D) //left rotate an array by D
{
    D=D%n;
    reverse(arr,0,D-1);
    reverse(arr,D-1,n-1);
    reverse(arr,0,n-1);
}
//[END] Left rotate an array by D
void LiaA (int arr[], int n)// leaders in an array
{
    int m = arr[n-1];
    vector<int> ans;
    ans.push_back(m); 
    for(int i =n-2; i>=0; i--)
    {
        if(arr[i]>m)
        {
            ans.push_back(arr[i]);
            m=arr[i];
        }
    }
    int size = ans.size();
    if(size!=0)
    {
        for(int i=size-1;i>=0;i--)
        {
            cout<<ans[i]<<" ";
        }
    }
}
//this is for Max Difference, that is max value of a[j]-a[i] where j>i
int MaxDifference1 (int arr[], int n)
{
    int maxnum = arr[n-1];
    int maxdiff=INT_MIN;
    for(int i =n-2; i>=0; i--)
    {
        if(arr[i+1]>maxnum) maxnum=arr[i+1];
        if(maxnum-arr[i]>maxdiff) maxdiff =maxnum-arr[i];
    }
    return(maxdiff);
} //O(n)
int MaxDifference2 (int arr[], int n)
{
    int minnum =arr[0];
    int maxdiff=INT_MIN;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]<minnum) minnum=arr[i-1];
        if(arr[i]-minnum>maxdiff) maxdiff=arr[i]-minnum;
    }
    return(maxdiff);
}//O(n)
//the end for Max Difference
void FiSA (int arr[], int n) //frequencies in a sorted array
{
    int count =1;
    for(int i=0; i<n-1;i++)
    {
        if(arr[i]==arr[i+1]) count++;
        else
        {
            cout<<arr[i]<<" "<<count<<"\n";
            count=1;
        }
    }
    cout<<arr[n-1]<<" "<<count<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {10,10,10,23,23,23,24,27,28,29,29,30};
    int size =sizeof(arr)/sizeof(arr[0]);
    FiSA(arr,size);
    // int t; 
    // cin>>t;
    // while(t--)
    // {
    //     int n;
    //     cin>>n;
    //     int a[n];
    //     for(int i=0; i<n;i++)
    //     {
    //         cin>>a[i];
    //     }
    //     cout<<MaxDifference1(a,n)<<" "<<MaxDifference2(a,n)<<"\n";
    // }
}