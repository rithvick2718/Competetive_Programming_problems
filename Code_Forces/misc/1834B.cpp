#include<bits/stdc++.h>
using namespace std;
int maxscore(string &L, string &R)
{
    if(L==R) return 0;
    if(L.length()< R.length())
    {
        for(int i=0 ; i<R.length(); i++)
        {
            L='0'+L;
        }
    }
    // now we know L and R have same number of zeros
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string L,R;
    while(t--)
    {
        cin>>L>>R;
    }
}