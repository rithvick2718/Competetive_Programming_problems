#include<bits/stdc++.h>
using namespace std;
vector<int> solve (vector<int> p)
{
    int n =(int)(p.size());
    n=n/2;
    vector<int> oddone(n-1);
    vector<int> evenone(n-1);
    for(int i=0;i<n-1;i++)
    {
        oddone[i]=p[2*i+1];
        evenone[i]=p[2*i+2];
    }
    n=2*n;
    sort(oddone.begin(),oddone.end());
    sort(evenone.begin(),evenone.end());
    vector<int> theone(n);
    if(oddone[0]>evenone[0]) //so we are pretty sure the least element is NOT 1 so the least value of ai will be 2n+2
    {
        auto pos = lower_bound(evenone.begin(), evenone.end(),p[0]);
        evenone.insert(pos,p[0]);
        pos = lower_bound(evenone.begin(), evenone.end(),p.back());
        evenone.insert(pos,p.back());
        for(int k :oddone)
        {
            theone[k-1]=n;
            n--;
        }
        for(int k :evenone)
        {
            theone[k-1]=n;
            n--;
        }
    }
    else
    {
        auto pos = lower_bound(oddone.begin(), oddone.end(),p[0]);
        oddone.insert(pos,p[0]);
        pos = lower_bound(oddone.begin(), oddone.end(),p.back());
        oddone.insert(pos,p.back());
        for(int k :evenone)
        {
            theone[k-1]=n;
            n--;
        }
        for(int k :oddone)
        {
            theone[k-1]=n;
            n--;
        }
    }
    return(theone);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        vector<int> p; //this is the og array
        vector<bool> eachone(n,true); //to keep check of what has been used
        int h; //the help variable
        while(n--)
        {
            cin>>h;
            p.push_back(h);
        }
        vector<int> ans =solve(p);
        for(int k : p)
        {
            cout<<ans[k-1]<<" ";
        }
        cout<<"\n";
    }   
}