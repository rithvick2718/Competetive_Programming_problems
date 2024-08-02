#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> sizes;
    int prev=0;
    int count=0;
    int h; //help variable
    while(n--)
    {
        cin>>h;
        if(h==prev)
        {
            count++;
            prev=h;
        }
        else
        {
            sizes.push_back(count);
            count=1;
            prev=h;
        }
    }
    if(count!=0) sizes.push_back(count);
    int size=sizes.size();
    int ans=0;
    for(int i=1;i<size-1;i++)
    {
        ans=max({min(sizes[i-1],sizes[i]),min(sizes[i],sizes[i+1]),ans});
    }
    cout<<2*ans;
}