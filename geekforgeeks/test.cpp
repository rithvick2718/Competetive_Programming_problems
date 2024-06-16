#include<iostream>
using namespace std;
int f(int n)
{
    if(n<=1)
    return(1);
    if(!(n&1)) return(f(n/2));
    return(f(n/2)+f(n/2+1));
}
int main()
{
    int arr[] = {9, 12, 2, 11, 2, 2, 10, 9, 12, 10, 9, 11, 2};
    int x = arr[0];
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=1; i<size;i++)
    {
        x=x^arr[i];
    }
    cout<<(5^3);
}