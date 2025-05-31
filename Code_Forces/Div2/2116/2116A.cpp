#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    vector<int> a(4);
    while(tt--){
        for(int i=0; i<4; i++) cin>>a[i];
        auto it = min_element(a.begin(),a.end());
        int pos = it-a.begin();
        int c=0;
        for(int i=0; i<4; i++) if(a[i]==a[pos]) c++;
        if(c==1){
            if(pos == 0 || pos ==2) cout<<"Flower\n";
            else cout<<"Gellyfish\n";
        }
        else{
            if(a[2]==a[pos] && (a[1] == a[pos] || a[3] == a[pos] )) cout<<"Gellyfish\n";
            else if(a[2]==a[pos] && a[0] == a[pos]) cout<<"Flower\n";
            else if(a[3]==a[pos]) cout<<"Gellyfish\n";
            else cout<<"Gellyfish\n";
        }
    }
}