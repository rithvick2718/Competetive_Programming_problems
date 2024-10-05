#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>k>>x;
    sort(a.begin(),a.end());
    auto it =upper_bound(a.begin(),a.end(),x);
    int min_index= distance(a.begin(),it)-1;
    int max_index= min_index+1;
    while(a[min_index]==x && min_index>=0) min_index--;
    deque<int> dq;
    while(k>0 && min_index>=0 && max_index<n)
    {
        if(x-a[min_index]<=a[max_index]-x){
            dq.push_front(a[min_index]);
            min_index--;
        }
        else{
            dq.push_back(a[max_index]);
            max_index++;
        }
        k--;
    }
    while(k>0 && min_index>=0)
    {
        
        dq.push_front(a[min_index]);
        min_index--;
        k--;
    }
    while(k>0 && max_index<n)
    {
        dq.push_back(a[max_index]);
        max_index++;
        k--;
    }
    for(auto p : dq)
    {
        cout<<p<<" ";
    }
}