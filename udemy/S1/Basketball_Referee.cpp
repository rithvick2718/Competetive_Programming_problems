// https://www.hackerrank.com/contests/udemy-welcome-contest/challenges/basketball-referee
#include<bits/stdc++.h>
using namespace std;
void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,r,d;
    fastscan(t);
    for(int i=0;i<t;i++)
    {
        fastscan(r);
        fastscan(d);
        if(r>d) cout<<"ROSE \n";
        else if(r==d) cout<<"DRAW \n";
        else cout<<"DAMON \n";
    }
}