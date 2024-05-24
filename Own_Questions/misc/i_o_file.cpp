//I am writing this program so that I can read from a .txt file and output a txt file
#include<bits/stdc++.h>
using namespace std;
string primefact(int n)
{
    ostringstream out;
    out<<"1";
    int i=0;
    while(n%2==0)
    {
        n=n/2;
        i++;
    }
    if(i!=0)
    out<<"x "<<2<<"^"<<i<<" ";
    //now n is odd so we do this
    int j=3; // j is our prime factor 
    while (n!=1)
    {
        i=0;
        while (n%j==0)
        {
            n=n/j;
            i++;
        }
        if(i!=0)
        out<<"x "<<j<<"^"<<i<<" ";
        j=j+2;
    }
    return (out.str());
}
int main()
{
    ifstream cin;
    cin.open("numbers.txt");
    vector<int> num;
    int k;
    while (cin >> k)
    {
        num.push_back(k);
    }
    cin.close();
    ofstream cout;
    cout.open("factorised.txt");
    for(int k : num)
    {
        cout<<k<<"="<<primefact(k);
        cout<<"\n";
    }
    cout.close();
}