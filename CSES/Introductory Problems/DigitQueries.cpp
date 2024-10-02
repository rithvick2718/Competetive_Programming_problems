#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q; //queries
    cin>>q;
    long long k; //input
    long long num_digits; // number of digits
    long long d; // working number
    long long rem;
    while(q--)
    {
        cin>>k;
        d=9LL;
        num_digits=1LL;
        while(k>d*num_digits)
        {
            k-=d*num_digits;
            d*=10;
            num_digits++;
        }
        // see that k>0 (cannot be equal to 0) and k<=d*i
        d/=9LL; // now d =1...0 with num_digits-1 zeros
        // now we want to convert d to the specific number we want
        rem=k%num_digits;
        if(rem==0) rem=num_digits;
        d+=(k-rem)/num_digits;
        rem=num_digits-rem;
        while(rem>0)
        {
            d/=10;
            rem--;
        }
        cout<<d%10<<"\n";
    }
}