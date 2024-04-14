//https://www.hackerrank.com/contests/udemy-welcome-contest/challenges/beautiful-numbers-questions
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
    int t,x;
    fastscan(t);
    for (int i = 0; i < t; i++)
    {
        fastscan(x);
        if(x%2!=0) cout<<3<<"\n";
        else if(x%4!=0) cout<<2<<"\n";
        else if(x%8!=0) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}