#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    while(t--)
    {
        int n; //lebngth of array
        cin>>n; //take it's vaalue
        int a; //the elementts of the array
        vector<int> toadd;
        cin>>a; // this is the first element
        int mx=a; //mx is max element
        for(int i=1; i<n;i++)
        {
            cin>>a;
            if(a>=mx) mx=a;
            else
            {
                toadd.push_back(mx-a); //these elements are +ve
            }
        }
        sort(toadd.begin(),toadd.end());
        int size =toadd.size();
        if(size==0) cout<<0<<"\n";
        else{
            int k=size+1;
            long long count =((long long)k)*((long long)toadd[0]);
            k--;
            for(int i=1; i<size; i++)
            {
                count+=(long long)(k)*((long long)(toadd[i]-toadd[i-1]));
                k--;
            }
            cout<<count<<"\n";
        }
    }
} //so a long long was the problem.