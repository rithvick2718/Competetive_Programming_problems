#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,x;
    while(t--)
    {
        //code
        cin>>n>>x;
        int a;
        vector<int> count(n,-1);
        for(int i=0; i<n ; i++)
        {
            cin>>a;
            if(a<n) count[a]++;
        }
        int mex=0;
        while(mex<n)
        {
            if(count[mex]>=0)
            {
                count[mex]--;
                mex++;
            }
            else
            {
                // so we don't have this in the array
                int p=mex%x;
                for(;p<mex;p+=x)
                {
                    if(count[p]>=0){
                        count[p]--;
                        break;
                    }
                }
                if(p>=mex) break;
                mex++;
            }
        }
        cout<<mex<<"\n";
    }
}