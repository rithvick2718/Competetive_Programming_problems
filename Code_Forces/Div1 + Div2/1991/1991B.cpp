#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //code
        int n;
        cin>>n;
        vector<int> b(n-1);
        for(int i=0; i<n-1;i++)
        {
            cin>>b[i];
        }//fine
        // Initialize the result array with zeros
        vector<int> a(n, 0);
        a[0] = b[0];
        bool isValid = true;
        // Iterate over the input array to construct the result array
        for (int i = 1; i < n - 1; ++i) {
            a[i] = b[i - 1] | b[i];
            if ((a[i - 1] & a[i]) != b[i - 1]) {
                isValid = false;
                break;
            }
        }
        // Set the last element of the result array
        a[n - 1] = b[n - 2];
        if (isValid && (a[n - 2] & a[n - 1]) != b[n - 2]) {
            isValid = false;
        }
        if(isValid)
        {
            for(auto p : a)
            {
                cout<<p<<" ";
            }
            cout<<"\n";
        }
        else cout<<-1<<"\n";
    }
}