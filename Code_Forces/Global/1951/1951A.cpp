#include<iostream>
#include<vector>
using namespace std;
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
        char h;
        vector<int> index;
        for(int i=0; i<n; i++)
        {
            cin>>h;
            if(h=='1') index.push_back(i);
        } //takes all the indexs which have 1
        int size =index.size();
        if(size&1) cout<<"NO\n"; //if we have odd number of 1's then it is not possible
        else{
            if(size==0) cout<<"YES\n"; //if we have 0
            else{
                size=size>>1;
                if(index[0]+1 == index[size]) cout<<"NO\n";
                else cout<<"YES\n";
            }
        }
    }
}