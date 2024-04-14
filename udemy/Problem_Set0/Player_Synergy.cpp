#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int p; //need to take look out for p=1
    cin>>p;
    long long int x= -100000; //this is exclusive for the greatest negative integer
    long long int s=1; //product
    long long int q; // so what if all q are 0's?
    int c =0; //counts the non-0's
    for(int i=0;i<p;i++)
    {
        cin>>q;
        if(q!=0) {s=s*q; c++;}
        if(q<0 && x<q) {x=q;}
    }
    if(c==0) //that is we have all 0's
    {
        cout<<0;
    }
    else
    {
        if(c==1)
        {
            if(s>0) cout<<s;
            else cout<<0;
        }
        else
        {
            if(s>0) cout<<s;
            else cout<<s/x;
        }
    }
    return 0;
}