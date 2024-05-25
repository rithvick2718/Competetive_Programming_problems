#include<bits/stdc++.h>
using namespace std;
int gcd(const int &a, const int &b)
{
    if(a==b) return(a);
    else if(a>b) return(gcd(a%b,b));
    else return(gcd(b%a,a));
}
int gcd2 (const int &a, const int &b)
{
    int m =a;
    int n=b;
    if(m)
    if(m>n) m=m%n;
}
int main()
{

}