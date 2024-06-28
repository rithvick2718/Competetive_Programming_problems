#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        //code
        int n;
        cin>>n;
        int a[n];
        int b[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
        vector<int> A,B;
        A.push_back(0);
        B.push_back(0);
        int s;
        for(int i=0; i<n;i++)
        {
            s=A.size();
            for(int j=0;j<s;j++)
            {
                if(A[j]>B[j])
                {
                    if(b[i]>=0) B[j]+=b[i]; //at no cost you can reduce min
                    else A[j]+=a[i];
                }
                if(B[j]>A[j])
                {
                    if(a[i]>=0) A[j]+=a[i]; //no way to reduce min
                    else B[j]+=b[i];
                }
                if(A[j]==B[j])
                {
                    //now we can go down two paths
                    if(a[i]!=0 && b[i]!=0)
                    {
                        A[j]=A[j]+a[i];
                        A.push_back(A[j]);
                        B.push_back(B[j]+b[i]);
                    }
                }
            }
        }
        int ans = min(A[0],B[0]);
        s=A.size();
        for(int i=1; i<s;i++)
        {
            ans =max(ans, min(A[i],B[i]));
        }
        cout<<ans;
    }
}