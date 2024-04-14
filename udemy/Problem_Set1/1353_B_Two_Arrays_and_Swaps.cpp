#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    size_t t;
    cin>>t;
    int n,k;
    vector<int> a,b;
    int A,B;
    while(t--)
    {
        //the code to be executed for each test case
        // I am conficted if I should write a function that does some work for me
        cin>>n>>k; //need to take n,k
        for(int i=0; i<n; i++)
        {
            cin>>A;
            a.push_back(A);
        }
        for(int i=0; i<n; i++)
        {
            cin>>B;
            b.push_back(B);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<k;i++)
        {
            if(b[n-1-i]>a[i]) a[i]=b[n-1-i];
        }
        int s = 0;
        for(int k : a)
        {
            s=s+k;
        }
        cout<<s<<"\n";
        a.clear();
        b.clear();
    }
}