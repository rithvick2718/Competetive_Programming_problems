#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int a[26]={};
    for(char c : s) // finding the number of A's B's ...
    {
        a[c-'A']++;
    }
    int odd=0; //the number of elements that appear odd number of times
    for(int i=0; i<26;i++)//loop to find odd
    {
        if(a[i]&1) odd++;
    }
    if(odd==0) //no odd
    {
        string t="";
        for(int i=0;i<26;i++)
        {
            for(int j=0; 2*j<a[i];j++)
            {
                t+=('A'+i);
            }
        }
        string r=t;
        for(int i =r.length()-1; i>=0 ;i--)
        {
            t+=r[i];
        }
        cout<<t;
    }
    else if (odd==1)
    {
        string t="";
        char hold;
        for(int i=0;i<26;i++)
        {
            if(a[i]&1) {
                hold ='A'+i;
            }
            else
            {
                for(int j=0; 2*j<a[i];j++)
                {
                    t+=('A'+i);
                }
            }
        }
        string r=t;
        for(int i=0; i<a[hold-'A'];i++)
            t+=hold;
        for(int i =r.length()-1; i>=0 ;i--)
        {
            t+=r[i];
        }
        cout<<t;
    }
    else
    {
        cout<<"NO SOLUTION";
    }
}