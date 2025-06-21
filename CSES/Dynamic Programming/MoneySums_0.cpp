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
    }
    set<int> prev;
    prev.insert(0);
    set<int> next;
    for(int i=0; i<n; i++){
        for(auto pr : prev){
            next.insert(pr+x[i]);
        }
        for(auto ne : next){
            prev.insert(ne);
        }
        next.clear();
    }
    prev.erase(0);
    cout<<prev.size()<<"\n";
    for(auto pr : prev) cout<<pr<<" ";
}