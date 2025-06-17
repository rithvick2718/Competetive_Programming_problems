#include<bits/stdc++.h>
using namespace std;
int w,h;
bool  cal(int x1, int x2, int y1, int y2,int a, int b)
{
    if(x1>x2){
        swap(x1,x2);
        swap(y1,y2);
    }
    bool ans = true;
    if(x1+a-1 < x2) ans = abs(x2-x1)%a == 0;
    else if(x1==x2){
        ans = (y2-y1)%b ==0;
    }
    else ans = false;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    int a,b,x1,x2,y1,y2;
    while(tt--){
        cin>>w>>h>>a>>b>>x1>>y1>>x2>>y2;
        bool ans = cal(x1,x2,y1,y2,a,b)|cal(y1,y2,x1,x2,b,a);
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}