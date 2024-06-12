#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n; //this is guarrented to be int type
        cin>>n; //take this
        long long int k; //10^12 so long long int
        cin>>k;
        vector<long long int> a(n); //all are 10^12 so long long int
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        } //get the array
        sort(a.begin(),a.end()); //sort it
        auto it = upper_bound(a.begin(),a.end(),a[0]);
        int toadd=(int)((it - a.begin())); //this has the number of elements equal at the start
        long long int diff = *it-a[0];
        while(k>=toadd*diff && toadd!=n)
        {
            a[0]=*it;
            k=k-toadd*diff;
            it = upper_bound(a.begin(),a.end(),a[0]);
            toadd=(int)((it - a.begin()));
            diff = *it-a[0];
        }
        //now either k< toadd*diff or toadd==n so that means
        //lets tackle it == a.end()
        a[0]=a[0]+k/toadd;
        k=k%toadd;
        cout<<((long long int)n)*(a[0])+((long long int)(k-toadd+1))<<"\n";
    }
}