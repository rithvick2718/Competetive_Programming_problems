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
int BSaS (int arr[], int n) //buy stocks and sell
{
    int profit=0;
    for(int i=0; i<n-1;i++)
    {
        if(arr[i]<arr[i+1]) profit += arr[i+1]-arr[i];
    }
    return(profit);
}
//Good
int TRW(int arr[], int n) //Trapping rainwater
{
    //the idea is pre computing
    int leftmax[n];
    leftmax[0]=arr[0];
    int rightmax[n];
    rightmax[n-1]=arr[n-1];
    for(int i=1;i<n;i++)
    {
        leftmax[i]=max(leftmax[i-1],arr[i]);
        rightmax[n-1-i]=max(arr[n-1-i],rightmax[n-i]);
    }
    int trappedwater=0;
    for(int i = 1; i<n-1; i++)
    {
        trappedwater+=min(leftmax[i],rightmax[i])-arr[i];
    }
    return(trappedwater);
}
int MC1(bool arr[], int n) //Maximum Consecutive 1's
{
    int count =0;
    int MAX =0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]) count++;
        else
        {
            MAX =max(MAX,count);
            count =0;
        }
    }
    MAX=max(MAX,count);
    return(MAX);
}
//these are the approaches to Maximum Sum Subarray problem
int MaximumSumSubarray1(int arr[], int n) //my first approach Time : O(n), Space : O(n) (extra)
{
    int presum[n];
    int minval[n];
    presum[0]=arr[0];
    minval[0]=0;
    int maxsum=presum[0]-minval[0];
    for(int i=1; i<n;i++)
    {
        presum[i]=presum[i-1]+arr[i];
        minval[i]=min(0,min(minval[i-1],presum[i-1]));
        maxsum=max(maxsum,presum[i]-minval[i]);
    }//O(n)
    return(maxsum);
}
int MaximumSumSubarray2(int arr[], int n) //Second approach(better) Time : O(n), Space : O(1)
{
    int presum =arr[0];
    int minval =0;
    int maxsum =presum-minval;
    for(int i=1; i<n;i++)
    {
        minval=min(0,min(presum,minval));
        presum+=arr[i];
        maxsum=max(maxsum, presum-minval);
    }//O(n)
    return(maxsum);
}
int MaximumSumSubarray3(int arr[], int n) //GFG Prof approach
{
    int res =arr[0];
    int maxending = arr[0];
    for(int i=1; i<n; i++)
    {
        maxending=max(maxending+arr[i],arr[i]);
        res = max(res, maxending);
    }
    return(res);
}
//the end of Maximum Subarray Problem
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {-2,-2,-1,-3,23,3,-321,4523,54,323,245325,45,325,235,345,45,4,-8765};
    int size =sizeof(arr)/sizeof(arr[0]);
    cout<<"First "<<MaximumSumSubarray1(arr,size)<<" Second "<<MaximumSumSubarray2(arr,size)<<" Thrid "<<MaximumSumSubarray3(arr,size);
    return(0);
}