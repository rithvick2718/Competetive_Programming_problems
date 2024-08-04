#include<iostream>
using namespace std;
int main()
{
    string t;
    cin>>t;
    int mx=-1;
    int con=1;
    int len =t.length();
    for(int i=1;i<len;i++)
    {
        if(t[i]==t[i-1]) con++;
        else
        {
            if(con>mx) mx =con;
            con=1;
        }
    }
    if(con>mx) mx =con;
    cout<<mx;
}