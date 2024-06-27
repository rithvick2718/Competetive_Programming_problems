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
//[END] Left rotate an array by D68
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
int LEOS(int arr[], int n) //longest even odd subarray
{
    int count =1;
    int max = 0;
    for(int i=0; i<n-1;i++)
    {
        if((arr[i]^arr[i+1])&1) count++; //^ is exclusive XOR so if we have even and odd pair or odd even, last bit will be 1 and if not it will be 1
        else
        {
           if(count>max) max =count;
           count =1; 
        }
    }
    if(count>max) max =count;
    return(max);
}
//Start Maximum Circular Subarray Sum
int MaximumCircularSubarraySum1 (int arr[], int n) //aproach 1(based on MaximumSumSubarray2)
{
    int minval=0;
    int maxval=0;
    int presum =arr[0];
    int maxsum=presum-minval;
    int minsum=presum-maxval;
    for(int i=1; i<n; i++)
    {
        minval=min({0,presum,minval});
        maxval=max({0,presum,maxval});
        presum +=arr[i];
        maxsum=max(maxsum,presum - minval);
        minsum=min(minsum,presum -maxval);
    }
    if(presum!=minsum) return max(maxsum,presum-minsum);
    return(maxsum);
}
int MaximumCircularSubarraySum2 (int arr[], int n) //aproach 2(based on MaximumSumSubarray3)
{
    int maxending=arr[0];
    int res1=arr[0];
    int minending=min(0,arr[0]);
    int res2 = min(0,arr[0]);
    int presum =arr[0];
    for(int i=1; i<n;i++)
    {
        presum=presum+arr[i];
        maxending=max({maxending+arr[i],arr[i]}); //this is the subarray sum with a[i]
        res1=max({res1,maxending});
        minending=min({minending+arr[i],arr[i]}); //this is the smallest subarray sum with a[i]
        res2=min({res2,minending});
    }
    if(presum!=res2) return (max(res1,presum-res2));
    return(res1);
}
int MaximumCircularSubarraySum3(int arr[], int n) //GFG prof approach
{
    int normalsum =MaximumSumSubarray3(arr,n);
    if(normalsum <0) return (normalsum);
    int sum=0;
    for(int i=0; i<n;i++)
    {
        sum+=arr[i];
        arr[i]=-arr[i];
    }
    int minsum = MaximumSumSubarray3(arr,n);
    return(max(normalsum, sum + minsum));
}
//end for Maximum Circular Subarray Sum
int MajorityElement(int arr[], int n)//Majority element of an array is the one that occurs more than n/2 in an array
{
    //first phase 
    int res=0;
    int count =1;
    for(int i=1; i<n;i++)
    {
        if(arr[res]==arr[i]) count ++;
        else count --;
        if(count ==0)
        {
            res=i;
            count =1;
        }
    }//This is Moore's voting algorithm
    //second phase to check if it is majority element
    count =0;
    for(int i=0;i<n;i++)
    {
        if(arr[res]==arr[i]) count ++;
    }
    if(count>n/2) return res;
    return -1;
}
void MCF(int arr[], int n ) //Minimum consecutive Flips
{
	for(int i = 1; i < n; i++)
	{
		if(arr[i] != arr[i - 1])
		{
			if(arr[i] != arr[0])
                cout << "From " << i << " to ";
			else
                cout << i - 1 << "\n";
		}
	}

	if(arr[n - 1] != arr[0])
        cout << n - 1 << "\n";
}
int SlidingWindowTechnique(int arr[], int n, int k) //Maximum Sum for Subarray of Size k, sliding window techique
{
    if(k>n) return -1;
    int sum = 0;
    for(int i=0; i<k;i++)
    {
        sum+=arr[i];
    }
    int max =sum;
    for(int i= 0; i<n-k;i++)
    {
        sum = sum -arr[i]+arr[i+k];
        if(sum>max) max =sum;
    }
    return(max);
}
//Solutions to Subarray with given sum, array if of non negative integers
bool SubarrayWithGivenSum (int arr[], int n, int k) //my approach 1
{
    // so I need to code this. well we must be better than O(n^2)
    int sum=0;
    int end=-1;
    while(sum < k && end<n-1) //the first run end=-1, as end++; end becomes zero
    {
        end++;
        sum+=arr[end];
    } //can run max n times O(n)
    if(sum == k ) return true;
    if(sum < k) return false;
    //so now we know (new)sum = (old)sum+ arr[end] >k but (old)sum <k
    int start=0;
    while(sum !=k && start<=end && end<n)
    {
        if(sum>k)
        {
            sum-=arr[start];
            start++;
        }
        if(sum<k)
        {
            sum+=arr[end];
            end++;
        }
    }// for each loop either end increase or start and start can increase n times and end can run can increase n-end
    //so this will run max 2*n -end times so overall <4n
    return(sum == k);
}
bool SubarrayWithGivenSum2 (int arr[], int n, int k) //approach after lecture same time complexity just neater
{
    int sum =0;
    int start=0;
    for(int end =0; end<n;end++)
    {
        sum+=arr[end];
        while(sum > k && start <=end)
        {
            sum-=arr[start];
            start++;
        }
        if(sum == k) return true;
    }
    return false;
}
int SubarrayWithGivenSumGFG (int arr[], int n, int sum) //GFG Solution
{ 
	/* Initialize curr_sum as value of first element 
	and starting point as 0 */
	int curr_sum = arr[0], start = 0, i; 

	/* Add elements one by one to curr_sum and if the curr_sum exceeds the 
	sum, then remove starting element */
	for (i = 1; i <= n; i++) 
	{ 
		// If curr_sum exceeds the sum, then remove the starting elements 
		while (curr_sum > sum && start < i-1) 
		{ 
			curr_sum = curr_sum - arr[start]; 
			start++; 
		} 

		// If curr_sum becomes equal to sum, then return true 
		if (curr_sum == sum) 
		{ 
			printf ("Sum found between indexes %d and %d", start, i-1); 
			return 1; 
		} 

		// Add this element to curr_sum 
		if (i < n) 
		curr_sum = curr_sum + arr[i]; 
	} 

	// If we reach here, then no subarray 
	printf("No subarray found"); 
	return 0; 
}
//end to solutions of Subarray with given sum, array if of non negative integers
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {4,8,12,5};
    int size =sizeof(arr)/sizeof(arr[0]);
    int k=29;
    if(SubarrayWithGivenSum(arr,size,k)) cout<<"YES";
    else cout<<"NO";
    cout<<" ";
    if(SubarrayWithGivenSum2(arr,size,k)) cout<<"YES";
    else cout<<"NO";
    return(0);
}