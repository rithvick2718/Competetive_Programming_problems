#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; //need to take
        cin>>n;
        int m =n/2; //as n is even working with m is easier
        int first; //the first and last numbers
        int last;
        vector<pair<int,int>> earr(m-1); //the even numbered array 
        vector<pair<int,int>> oarr(m-1); //the odd numbered array
        int esum=0;
        int osum=0;
        cin>>first; //Read the first element
        int h;
        for (int i = 0; i < m-1; i++)
        {
            cin>>h;
            esum=esum+h;
            earr[i]={h,2*i+2};
            cin>>h;
            osum=osum+h;
            oarr[i]={h,2*i+3};
        }
        cin>>last; //Read the last element
        int q[2*m];
        if(esum>osum)
        {
            oarr.push_back({first,1});
            oarr.push_back({last,n});
            sort(earr.begin(),earr.end());
            sort(oarr.begin(),oarr.end());
            for(int i=0; i< (int)earr.size();i++)
            {
                q[earr[i].second-1] =n-i;
            }
            for(int i=0; i< (int)oarr.size(); i++)
            {
                q[oarr[i].second-1]= n-((int)earr.size())-i;
            }
        }
        else
        {
            earr.push_back({first,1});
            earr.push_back({last,n});
            sort(oarr.begin(),oarr.end());
            sort(earr.begin(),earr.end());
            for(int i=0; i< (int)oarr.size();i++)
            {
                q[oarr[i].second-1] =n-i;
            }
            for(int i=0; i< (int)earr.size(); i++)
            {
                q[earr[i].second-1]= n-((int)oarr.size())-i;
            }
        }
        for(int i=0; i<2*m; i++)
        {
            cout<<q[i]<<" ";
        }
        cout<<"\n";
    }
}