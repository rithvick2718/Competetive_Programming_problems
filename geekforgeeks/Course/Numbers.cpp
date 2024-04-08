#include <bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
int fact1(int n)
{
    if(n==0)
    return(1);
    else
    {
        int m=1;
        for(int i=0; i<n;i++)
        m=m*(i+1);
        return m;
    }
}
int fact2(int n)
{
    if(n==0)
    return(1);
    else
    return(n*fact2(n-1));
}
int count(int n)
{
    int i=0;
    do
    {
        n=n/10;
        i++;
    } while (n>=1);
    return(i);
}
int myPow(int x, unsigned int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;
  
  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
} // this is a recursive solution taking O(log n) time complexity and O(log n) space compexity
int iterpow(int n, unsigned int p)
{
    int x=p; // for bit representation
    int y =n; // even powers of n
    int r=1; // actual value of n^p
    do
    {
        if(x%2==1)
        {
            r=r*y;
        }
        y=y*y;
        x=x/2;
    }while(x!=0);
    return(r);
}// my guess for the iterative solution that takes O(log n) time complexity O(1) space complexity
//in this I need bit representation of p, value of n^(2^m) and n^p
// it is same as sir's first solution the better one directly uses bit shift
int ipowop(int n, unsigned int p)
{
    int x=p; // for bit representation
    int y =n; // even powers of n
    int r=1; // actual value of n^p
    do
    {
        if(x%2==1)
        {
            r=r*y;
        }
        y=y*y;
        x=x>>1;
    }while(x!=0);
    return(r);
}// the same as above just with bit shift operator
bool palindrome (int n)
{
    int m=0;
    int o =n;
    while(o>=1)
    {
        m=10*m+(o%10);
        o=o/10;
    }
    return(m==n);
}
int t0nf (int n) //trail of zero's in n factorial so t0nf
{
    int s=0;
    while(n!=0)
    {
        s=s+(n/5);
        n=n/5;
    }
    return(s);
}
int HCF1 (int n, int m)
{
    if(m>=n)
    {
        int r;
        while (r!=0)
        {
            r=m%n;
            m=n;
            n=r;
        }
        return(m);
    }
    else
    return HCF1(m,n);
}
int HCF2 (int n, int m)
{
    if(m==0)
    return (n);
    else
    return HCF2(m,n%m);
}
int LCM (int n, int m)
{
    return((n*m)/(HCF1 (n,m)));
}
bool checkPrime (int n) // works only upto 2147483647 sed lyf add crying rithvick. can't show that 6309552037 is prime
{
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
void primefact1 (int n)
{
    while(n%2==0)
    {
        cout<<2<<"\t";
        n=n/2;
    }
    int i=3;
    while (n!=1)
    {
        while(n%i==0)
        {
            cout<<i<<"\t";
            n=n/i;
        }
        i=i+2;
    }
}
void primefact2 (int n)
{
    if(n<=1)
    return;
    while(n%2==0)
    {
        cout<<2<<"\t";
        n=n/2;
    }
    while(n%3==0)
    {
        cout<<3<<"\t";
        n=n/3;
    }
    for(int i = 5; i*i<=n; i=i+6)
    {
        while(n%i==0)
        {
            cout<<i<<"\t";
            n=n/i;
        }
        while(n%(i+2)==0)
        {
            cout<<i+2<<"\t";
            n=n/(i+2);
        }
    }
    if(n>3)
    cout<<n;
}
void printdiv (int n)
{
    
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        cout<<i<<"\t";
    }
    for(;i>=1;i--)
    {
        if(n%i==0)
        cout<<n/i<<"\t";
    }
}
void sievedontwork (int n)
{
    bool p[n];
    for(int i=0;i<n;i++)
    {
        p[i]=true;
    }
    for(int i =2;i<n;i++)
    {
        if(p[i-1]==true)
        {
            cout<<i<<"\t";
            // for(int j=i+1;j<=n;j++)
            // {
            //     if(p[j-1]==true && j%i==0)
            //     p[j-1]=false;

            // }
            for(int j=2;j*i<=n;j++)
            p[j*i-1]=false;
        }
    }

}//not sure why it fails *insert crying face*
void sievework (int n)
{
    vector<bool>prime(n+1,true);
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            cout<<i<<"\t";
            for(int j=i*i;j<=n;j=j+i)
            {
                prime[j]=false;
            }
        }
    }
} //O(n log log n)
int exactly3Divisors(int N)
{
    int n = sqrt(N); // the answer depends on the number of primes less than sqrt(N)
    vector<bool> prime(n+1,true); //using sieve of erathoneses, I am creating a boolean arrray that keeps marking multiples of prime as false
    int s=0; // the number that does counting 
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            s++;
            for(int j=i*i;j<=n;j=j+i)
            {
                prime[j]=false;
            }
        }
    }
    return (s);
}
vector<int> quadraticRoots(int a, int b, int c) 
{
        int D = b*b-4*a*c;
        vector<int> q;
        if(D>=0)
        {
        long double x1 =(-b+sqrt(D))/(2.0*a);
        long double x2 =(-b-sqrt(D))/(2.0*a);
        long double r1 = max(x1,x2);
        long double r2 = min(x1,x2);
        q.push_back(floor(r1));
        q.push_back(floor(r2));
        }
        else 
        q.push_back(-1);
        return q;
}//this bastard question in C++ is troubling me as my answer is not being rounded properly
double termOfGP(int A,int B,int N)
    {
        double C = (double)B/A; // the ratio and also acts as even powers
        double m = (double)A; // this is the value I will return
        int n =N-1; // bit representation of power
        do
        {
            if(n%2==1)
            {
                m=m*C;
            }
            C=C*C;
            n=n/2;
        }while(n!=0);
        return(m);
    }
int main()
{   
    cout<<checkPrime(253);
} //i've just learned that value of n won't change if we use a function, I've got to update about this