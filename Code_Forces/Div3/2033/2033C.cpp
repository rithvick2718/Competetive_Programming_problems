#include<bits/stdc++.h>
using namespace std;
int find_dist(int a, int b, int c, int d)
{
    if(a!=b){
        if(c!=d){
            return 0;
        }
        else{
            if(a==c) return 1;
            if(b==c) return 1;
            return 0;
        }
    }
    //a==b
    if(c!=d){
        if(a==c) return 1;
        if(a==d) return 1;
        return 0;
    }
    //a==b c==d
    if(a==c) return 2;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,n;
    cin>>tt;
    while(tt--)
    {
        //code
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int disturbance=0;
        int p1,p2,q1,q2;
        for(int i=0; i+1 < n/2; i++)
        {
            p1=a[i];
            p2=a[n-1-i];
            q1=a[i+1];
            q2=a[n-2-i];
            // write function
            disturbance+=find_dist(p1,p2,q1,q2);
        }
        if(n&1){
            int i=n/2;
            if(a[i-1]==a[i]) disturbance++;
            if(a[i]==a[i+1]) disturbance++;
        }
        else
        {
            int i=n/2;
            if(a[i]==a[i-1]) disturbance++;
        }
        cout<<disturbance<<"\n";
    }
}