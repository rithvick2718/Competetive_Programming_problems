#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //test cases
    cin>>t;
    int q; //queries
    while(t--)
    {
        cin>>q;
        int first,x;
        cin>>first;
        cout<<1;
        q--;
        int prev = first;
        while(q>0)
        {
            q--;
            cin>>x;
            if(x>=prev){
                cout<<1;
                prev=x;
            }
            else
            {
                if(x<=first){
                    cout<<1;
                    prev=x;
                    break;
                }
                else
                {
                    cout<<0;
                    continue;
                }
            }
        }
        while(q>0)
        {
            q--;
            cin>>x;
            if(x>=prev && x <= first)
            {
                cout<<1;
                prev=x;
            }
            else cout<<0;
        }
        cout<<"\n";
    }
}