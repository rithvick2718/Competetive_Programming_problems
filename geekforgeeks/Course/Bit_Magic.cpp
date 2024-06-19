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
//the function below is to calculate the set bits from 1 to n
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
// int checkpattern and maxAND are amazing problems
//see you start out with an answer=0 and you traverse from the largest bit here 31.
//now what we do is we check if there are atleat 2 numbers such that ( res|(1<<i) ) & a[i] = ( res|(1<<i) )
// then we can update res = res | (1<<i)
//see when we start with 0 we see that to maximize result we need to start from the left and go right
// so we see the first time we have atleast 2 1's and then add it
// now we have a res like 100000
// now we see if there are numbers whose start part is like the start of res|(1<<i) see that res will have 0's after ith place
//so taking an and we will get back res
// continuing this we have our answer. this is brilliant.
int checkpattern(int pattern, int arr[], int N)
{
	int count =0;
	for(int i=0; i<N;i++)
	{
		if((pattern&arr[i])==pattern) count++;
	}
	return(count);
}
int maxAND (int arr[], int N) //N is the size of arr[] so you don't have to
{
	int ans =0;
	int count;
	for(int i =31; i>=0; i--)
	{
		count =checkpattern(ans|(1<<i),arr,N);
		if(count >=2) ans = ans|(1<<i);
	}
	return(ans);
}
int greyConverter(int n)
{        
    // Your code here
	return(n^(n>>1));
}
int grayToBinary(int n)
{
	int k =fbit(n); //this is the total bits in n
	int ans = 1<<(k-1); //now ans and n have the same MSB
	int binbit=1; //this is the status of binary bit
	int graybit;
	for(;k>1;k--)
	{
		graybit= (n>>(k-2))&1;
		if(binbit^graybit){
			ans = ans+(1<<(k-2));
			binbit=1;
		}
		else binbit =0;
	}
	return(ans);
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int n;
	while (t--)
	{
		cin>>n;
		cout<<grayToBinary(n)<<"\n";
	}
}