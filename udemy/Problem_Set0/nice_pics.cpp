
#include<bits/stdc++.h>
using namespace std; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // there are not many time or space constraints, so I am going to brute-fore my way
    int h,w,x;
    cin>>h;
    cin>>w;
    vector<int> primes;
    vector<bool> isPrime(256,true);
    for(int i =2; i<256;i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i); //storing primes
            for(int j=2*i;j<256;j=j+i)
            {
                isPrime[j]=false;
            }
        }//killing composites
    }//storing primes
    int s= primes.size();
    int d;
    vector<bool>p3sum(766,false);
    for (int a=0;a<s;a++)
    {
        for (int b =a;b<s;b++)
        {
            for(int c=b;c<s;c++)
            {
                d = primes[a]+primes[b]+primes[c];
                p3sum[d]=true;
            }
        }
    }
    for(int i=0; i<h*w; i++)
    {
        cin>>x;
        if(x>=0 && x<765)
        {
            if(p3sum[x]) cout<<"POSSIBLE\n";
            else cout<<"IMPOSSIBLE\n";
        }
        else cout<<"IMPOSSIBLE\n";
    }
    return 0;
}