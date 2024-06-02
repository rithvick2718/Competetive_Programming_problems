#include<bits/stdc++.h>
using namespace std;
int findthen(int num)
{
    int bits = 0;
    while (num != 0) {
        num >>= 1;
        bits++;
    }
    bits--;
    return bits;
}
int main()
{
    int t;
    cin>>t;
    int l,r;
    while(t--)
    {
        //write the code for each test case here
        cin>>l>>r; //getting l,r I guess l is nearly irrelevant
        cout<<findthen(r)<<"\n";
    }
}