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
int main ()
{
    int a[]={2,2,2,9,7,7,8,8,9,9,9,5,5,5,5,7,2,8};
    for(auto x : two_odd_occuring2(a,18))
    {
        cout<<x<<" ";
    }
}