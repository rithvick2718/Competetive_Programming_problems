#include<bits/stdc++.h>
using namespace std;
int cal(const int &l, const int &r, const vector<int[30]> &pre) //have debugged enough
{
    if(l>r) return 0;
    int ans=0;
    for(int i=0; i<30; i++)
    {
        if((pre[r][i]-pre[l-1][i])==((r-l)+1)) ans = ans|(1<<i);
    }
    return(ans);
}
int findr(const int &l, const int &k, const vector<int[30]> &pre, const int &n) //the final one.
{
    int low = l;
    int high = n;
    while (low < high)
    {
        int mid = low + (high - low + 1) / 2; //this +1 was the mole. Let's figure out why
        if (cal(l, mid, pre) >= k)
            low = mid;
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;  //testcases
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n+1); //This is the OG array
        a[0]=0; //I just want better indexing
        vector<int[30]> pre(n+1); // THE PREFIX ARRAY
        for(int j=0; j<30; j++) //setting the pre[0] to be all 0
        {
            pre[0][j]=0;
        }
        for (int i = 1; i <= n; i++) //getting the OG array as well as PREFIX array
        {
            cin>>a[i];
            for(int j=0; j<30; j++)
            {
                if((a[i]>>j)&1) pre[i][j]=pre[i-1][j]+1;
                else pre[i][j]=pre[i-1][j];
            }
        } //so I have debugged everything till here in main()
        int q;
        int l,k;
        cin>>q;
        while(q--)
        {
            cin>>l>>k;
            if(a[l]<k) cout<<-1<<" ";
            else cout<<findr(l,k,pre,n)<<" ";
        }
        cout<<"\n";
    }
}