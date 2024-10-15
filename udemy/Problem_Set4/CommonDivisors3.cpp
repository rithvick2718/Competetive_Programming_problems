#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    int r=a%b; //a,b>0
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
bool check(string &s, int i)
{
    int pos=0;
    while(pos+i<=s.length()){
        if(s.substr(0,i)!=s.substr(pos,i)) return false;
        pos+=i;
    }
    return true;
}
int number_of_div(int n)
{
    // if(n==1) return 1;
    int ans=0;
    int i=1;
    for(; i*i<=n; i++)
    {
        if(n%i==0) ans++;
    }
    ans<<=1;
    if((i-1)*(i-1)==n) ans--;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout<<number_of_div(81900)<<"\n";
    string s1,s2;
    cin>>s1>>s2;
    int g=gcd((int) s1.length(),(int) s2.length());
    bool is_cd=(s1.substr(0,g)==s2.substr(0,g));
    if(is_cd) is_cd=check(s1,g);
    if(is_cd) is_cd=check(s2,g);
    if(is_cd){
        // cout<<"arrived";
        s1=s1.substr(0,g);
        int i=1;
        for(; i*i<=g ;i++)
        {
            if(g%i==0){
                if(check(s1,i)){
                    cout<<number_of_div(g/i);
                    is_cd=false;
                    break;
                }
            }
        }
        if(is_cd){
            for(; i>0;i--)
            {
                if(g%i==0){
                    if(check(s1,g/i)){
                        cout<<number_of_div(i);
                        break;
                    }
                }
            }
        }
    }
    else cout<<0;
    return 0;
}