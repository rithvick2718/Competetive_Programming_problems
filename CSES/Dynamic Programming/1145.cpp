#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> subsequence;
    int x;
    vector<int>::iterator it;
    for(int i=0; i<n; i++){
        cin>>x;
        it = lower_bound(subsequence.begin(),subsequence.end(),x);
        if(it == subsequence.end()) subsequence.push_back(x);
        else *it=x;
    }
    cout<<subsequence.size();
}