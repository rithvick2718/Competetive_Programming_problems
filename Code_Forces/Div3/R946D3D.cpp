#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); //must
    int t; //testcases
    cin>>t;
    int n; //declaring n before
    int a[4]; //stores n,s,w,e
    while(t--) //code for each testcase
    {
        cin>>n; //take n
        char h; //help variable to fill string array
        a[0]=0; // N
        a[1]=0; // S
        a[2]=0; // W
        a[3]=0; // E
        //set 0 for each test case
        string s;
        for (size_t i = 0; i < n; i++)
        {
            cin>>h;
            if(h=='N') a[0]++;
            else if(h=='S') a[1]++;
            else if(h=='W') a[2]++;
            else if(h=='E') a[3]++;
            s.push_back(h);
        } //fine
        string sol;
        int N=a[0];
        int S=a[1];
        int W=a[2];
        int E=a[3];
        if((a[0]-a[1])%2==0 && (a[2]-a[3])%2==0 ) // diff must be even 
        {
            for(int i=0; i<n; i++)
            {
                if(s[i]=='N' || s[i]=='S')
                {
                    
                }
            }
        }
        else
        {
            sol ="NO";
        }
        cout<<sol<<"\n";
    }
}