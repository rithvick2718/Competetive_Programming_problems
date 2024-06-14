#include<bits/stdc++.h>
using namespace std;
vector<int> two_odd_occuring1 (int arr[], int n) // we need the array firstly n is size of arr
{
	vector<int> t;
	int m = 0; // now we take xOr of all elements
	for(int j =0; j<n; j++)
		m=m^arr[j]; // after this we get m, if it was one occuring this would have been the answer
	int i=0;
	while(((m>>i)&1)==0) {i++;} //finding the first bit that is 1
	int a=0; 
	int b=0; //a and b will be our final answer
	for(int j=0; j<n; j++)
	{
		if((arr[j]>>(i))&1 == 1) //since we are taking xor we know that if at ith position we have 1 for a and 0
		a=a^arr[j];              // so we divide the array into two disjoint sets one having 1 in the ith place so that array will have a and other b 
		else
		b=b^arr[j];
	}
	t.push_back(a);
	t.push_back(b);
    return (t);
}
vector<int> two_odd_occuring2 (int arr[], int n) // we need the array firstly n is size of arr
{
	vector<int> t;
	int m = 0; // now we take xOr of all elements
	for(int j =0; j<n; j++)
		m=m^arr[j]; // after this we get m, if it was one occuring this would have been the answer
	int k = (m&(~(m-1))); //this part is different and better than previous method instead of a loop we perform a calculation similar to 	Brian and Kerningham Algorithm
    int a=0;            //k will have the last 1 in m and rest 0
	int b=0; //a and b will be our final answer
	for(int j=0; j<n; j++)
	{
		if((arr[j]&k)==0) //since we are taking xor we know that if at ith position we have 1 for a and 0
		b=b^arr[j];       // so we divide the array into two disjoint sets one having 1 in the ith place so that array will have a and other b 
		else
		a=a^arr[j];
	}
	t.push_back(a);
	t.push_back(b);
    return (t);
}
int fbit (int n) //debugged
{
	int ans=0;
	while(n)
	{
		ans++;
		n>>=1;
	}
	return(ans);
}
int countSetBits(int n) //so I write a iterative solution
{
	if (n==0) return 0;
	if(n==1) return 1;
	int a = fbit(n); //we are dam sure a>=2
	int ans =0;
	while(a>=2)
	{
		ans =ans+n-(1<<(a-1))+1+(a-1)*(1<<(a-2));
		n=n-(1<<(a-1));
		a =fbit(n);
	}
	if(n&1) ans++;
	return(ans);
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	cout<<countSetBits(t);
}