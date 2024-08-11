#include<iostream>
using namespace std;
int calculatetower(int n)
{
    if(n==0) return 0;
    return 2*calculatetower(n-1)+1;
}
void printtowerofhanoi (int from, int to, int middle, int n)
{
    if(n==0) return;
    printtowerofhanoi(from, middle, to, n-1);
    cout<<from<<" "<<to<<"\n";
    printtowerofhanoi(middle, to, from, n-1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<calculatetower(n)<<"\n";
    printtowerofhanoi(1,3,2,n);
}