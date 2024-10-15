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
    string s1,s2;
    cin>>s1>>s2;
    int g=gcd((int) s1.length(),(int) s2.length());
    // now if s1 and s2 have a common divisor x then x.lenght()|a.length() && x.lenght()|b.length() so
    // x.length()|gcd(a.length(),b.length())=g so that means the first g letters of a and b must be same
    bool have_cd=(s1.substr(0,g)==s2.substr(0,g));
    int pos=0;
    while(have_cd && pos+g<=s1.length()){
        have_cd=(s1.substr(0,g)==s1.substr(pos,g));
        pos+=g;
    }
    pos=0;
    while(have_cd && pos+g<=s2.length()){
        have_cd=(s1.substr(0,g)==s2.substr(pos,g));
        pos+=g;
    }
    if(have_cd){
        //now we need to find the smallest common divisor of g, we know that is cd.lenght()|g.length()
        have_cd=false;
        int i=1;
        for(; i*i<=g; i++){
            if(g%i==0){
                //I can write a function but I wont.
                pos=0;
                while(s1.substr(0,i)==s1.substr(pos,i) && pos+i<=g) {
                    pos+=i;
                }
                if(pos==g){
                    have_cd=true;
                    break;
                }
            }
        }
        if(have_cd) cout<<number_of_div(g/i);
        else{
            int j;
            for(;i>=1;i--){
                if(g%i==0){
                    j=g/i;
                    pos=0;
                    while(s1.substr(0,j)==s1.substr(pos,j)&&pos+j<=g){
                        pos+=j;
                    }
                    if(pos==g){
                        break;
                    }
                }
            }
            cout<<number_of_div(i);
        }
    }
    else cout<<0;
    return 0;
}