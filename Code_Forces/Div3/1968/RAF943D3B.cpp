#include<bits/stdc++.h>
using namespace std;
vector<int> solver (vector<bool> bar)
{
    vector<int> a;
    int c=1;
    if((int) bar.size() ==1) a.push_back(1);
    else
    {
        for(int i=1; i<(int) bar.size() ; i++)
        {
            if(bar[i]==bar[i-1]) 
            {
                c++;
                if(i==(int) bar.size()-1)
                a.push_back(c);
            }
            else
            {
                a.push_back(c);
                c=1;
                if(i==(int) bar.size()-1)
                a.push_back(c);
            }
        }
    }
    return(a);
}
//this stores the number of 1's and 0's
int compare(vector<int>c, vector<int> d, bool a, bool b) //a and b are the first terms of the binary array
{
    int ans=0;
    int m= (int) c.size();
    int n= (int) d.size();
    if(a==b)
    {
        int j=0;
        for(int i=0;i<m && j<n; i++)
        {
            while(c[i]!=0 && j< n)
            {
                if(d[j]>0) 
                {
                    d[j]--;
                    c[i]--;
                    ans++;
                }
                else j=j+2;
            }
            j++;
        }
    }
    else
    {
        int j=1;
        for(int i=0;i<m && j<n; i++)
        {
            while(c[i]!=0 && j< n)
            {
                if(d[j]>0) 
                {
                    d[j]--;
                    c[i]--;
                    ans++;
                }
                else j=j+2;
            }
            j++;
        }
    }
    return(ans);
}
int main()
{
    int t;
    cin>>t;
    char h; //the help variable
    int n,m;
    vector<bool> a;
    vector<bool> b;
    vector<int> c;
    vector<int> d;
    while(t--)
    {
        cin>>n>>m;
        for (size_t i = 0; i < n; i++)
        {
            cin>>h;
            a.push_back((h=='1'));
        }
        for (size_t i = 0; i < m; i++)
        {
            cin>>h;
            b.push_back((h=='1'));
        } // getting the arrays
        c = solver(a);
        d = solver(b);
        cout<<compare(c,d,a[0],b[0])<<"\n";
        a.clear(); //clearing them for next test case
        b.clear();
        c.clear();
        d.clear();
    }
}