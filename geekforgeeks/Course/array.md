# This has the solutions to some interesting questions
## The maximum subarray problem
Approach 1
```
int MaximumSumSubarray(int arr[], int n)
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
```
The explanation :  
`presum[i]=arr[0]+arr[1]...+arr[i]`  
`minval[i]=minimum{0,presum[0],presum[1]...presum[i-1]}`  
So `presum[i]-minval[i]` is that largest subarray that can be formed by including `arr[i]`  
So our answer is `maxsum=max{presum[i]-minval[i]}` $ \forall i $

Approach 2
```
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
```
In the above we improve space complexity
```
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
```
This is the solution given by the professor
