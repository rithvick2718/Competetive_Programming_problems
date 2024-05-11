#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin>>N;
    cin>>K; //the idea is simple
    if(K>=N)
    {
        cout<<N;
        return(0);
    }
    else
    {
        vector<int> arr;
        int a,temp;
        cin>>a;
        temp =a;
        for(int i=0;i<N-1;i++)
        {
            cin>>a;
            arr.push_back(a-temp-1);
            temp=a;
        }
        sort(arr.begin(),arr.end());
        int s=N;
        for(int i=0; i<N-K; i++)
        {
            s=s+arr[i];
        }
        cout<<s;
    }
    return(0);
} //hey! this is a test!