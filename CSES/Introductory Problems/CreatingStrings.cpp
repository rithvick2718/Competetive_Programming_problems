#include<bits/stdc++.h>
using namespace std;
void printstrings(string &k)
{
    set<string> s;
    sort(k.begin(),k.end());
    do
    {
        s.insert(k);
    } while (next_permutation(k.begin(),k.end()));
    cout<<s.size()<<"\n";
    for( string p : s)
    {
        cout<<p<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string k;
    cin>>k;
    printstrings(k);
}