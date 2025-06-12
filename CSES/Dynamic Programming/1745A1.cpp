#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> x(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        sum+=x[i];
    } //fine, I take all the values and the total sum so the max size of the array is fixed.
    vector<bool> prev(1+sum,false);
    prev[0]=true;
    vector<bool> next=prev;
    int current_sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=current_sum; j++){
            if(prev[j]){
                next[j+x[i]]=true;
            }
        }
        current_sum+=x[i];
        prev=next;
    }
    vector<int> ANS;
    for(int i=1; i<=sum; i++){
        if(next[i]) ANS.push_back(i);
    }
    cout<<ANS.size()<<"\n";
    for(auto ans : ANS) cout<<ans<<" ";
}