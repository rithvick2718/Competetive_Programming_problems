#include<bits/stdc++.h>
using namespace std;
void taskone (vector<int> &a)
{
    //this is sorted
    vector<int>b;
    int size = a.size();
    int count=1;
    for(int i=0; i<size-1; i++)
    {
        if(a[i]==a[i+1]) count ++;
        else{
            if(count&1) b.push_back(a[i]);
            count =1;
        }
    }
    b.push_back(a[size-1]);
    a=b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    while(t--)
    {
        //code for each testcase
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0; i<n;i++)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        taskone(a);
    }
}