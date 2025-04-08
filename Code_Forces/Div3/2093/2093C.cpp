#include<bits/stdc++.h>
using namespace std;
bool checkPrime (int n) // works only upto 2147483647 sed lyf add crying rithvick
{
    if(n==1) return false;
    if(n==2 || n==3 || n== 5 || n==7)
    return true;
    else if(n%2==0 || n%3 == 0)
    return false;
    else
    {
        int i=1;
        bool p= (n%(6*i-1)!=0 && n%(6*i+1)!=0);
        while(p && (6*i-1)*(6*i-1)<=n)
        {
            i++;
            p=p&&(n%(6*i-1)!=0)&&(n%(6*i+1)!=0);
        }
        return p;
    }
}
int build(int k)
{
    int a=0;
    int b=10;
    int to_add=1;
    while(k--)
    {
        a+=to_add;
        to_add*=10;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int x,k;
        cin>>x>>k;
        if(x!=1){
            if(k!=1) cout<<"NO\n";
            else {
                if(checkPrime(x)) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
        else
        {
            k=build(k);
            if(checkPrime(k)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}