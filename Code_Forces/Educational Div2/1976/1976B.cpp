#include<bits/stdc++.h>
using namespace std;
void insertclosetindex(vector<int>& a, const int &value)
{
    unsigned int minimum = UINT_MAX;
    int index=0;
    unsigned int k;
    for(int i=0; i<a.size();i++)
    {
        k=(unsigned int)(abs(a[i]-value));
        if(k<minimum)
        {
            index=i;
            minimum=k;
        }
    }
    a.push_back(a[index]);
}
int main()
{
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        //the code for each test case
        cin>>n;
        int op=0;
        vector<int> a;
        vector<int>b;
        int h;
        for (size_t i = 0; i < n; i++)
        {
            cin>>h;
            a.push_back(h);
        }
        for (size_t i = 0; i < n; i++)
        {
            cin>>h;
            op=op+(int)(abs(a[i]-h));
            b.push_back(h);
        }
        cin>>h;
        b.push_back(h);
        insertclosetindex(a,b.back());
        op=op+1+(int)(abs(a[n]-b[n]));
        cout<<op<<"\n";
    }
}