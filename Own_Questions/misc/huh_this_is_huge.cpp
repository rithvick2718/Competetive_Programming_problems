#include<iostream>
#include<gmpxx.h>
using namespace std;
int main()
{
    mpz_class a ("8866128975287528");
    mpz_class b ("8778405442862239");
    mpz_class c ("2736111468807040");
    a=a*a*a;
    b=b*b*b;
    c=c*c*c;
    cout<<a-b-c;
}
//g++ D:\Work\Competetive_Programming_problems\Own_Questions\misc\huh_this_is_huge.cpp -o huh_this_is_huge.exe -lgmp -lgmpxx