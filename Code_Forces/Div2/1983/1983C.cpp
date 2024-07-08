#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> MAKEIT(vector<int> &a, int tot)
{
    vector<pair<int,int>> ans;

    auto it = std::lower_bound(a.begin(), a.end(), tot / 3);
    int index = std::distance(a.begin(), it);
    ans.push_back({1,index+1});

    it = std::upper_bound(a.begin(), a.end(), tot / 3);
    int ind = std::distance(a.begin(), it);
    it = std::lower_bound(a.begin(), a.end(), (2*tot) / 3);
    index = std::distance(a.begin(), it);
    ans.push_back({ind+1, index+1});

    it = std::upper_bound(a.begin(), a.end(), tot / 3);
    ind = std::distance(a.begin(), it);
    ans.push_back({ind+1,a.size()});
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    int copy =t;
    while(t--)
    {
        //code for each testcase
        cout<<"Testcase :"<<copy-t<<"\n";
        cin>>n;
        vector<int> a(n),b(n),c(n);
        cin>>a[0];
        for(int i=1; i<n; i++)
        {
            cin>>a[i];
            a[i]+=a[i-1];
        }
        cin>>b[0];
        for(int i=1; i<n; i++)
        {
            cin>>b[i];
            b[i]+=b[i-1];
        }
        cin>>c[0];
        for(int i=1; i<n; i++)
        {
            cin>>c[i];
            c[i]+=c[i-1];
        }
        //now I have the arrays
        //see that these are prefix arrrays
        // now a[n-1]=b[n-1]=c[n-1] = tot
        int tot =a[n-1];
        vector<pair<int,int>> A,B,C;
        A=MAKEIT(a,tot);
        B=MAKEIT(b,tot);
        C=MAKEIT(c,tot);
        cout<<"A\t";
        for(auto x : A)
        {
            cout<<x.first<<" "<<x.second<<"\t";
        }
        cout<<"\n";
        cout<<"B\t";
        for(auto x : B)
        {
            cout<<x.first<<" "<<x.second<<"\t";
        }
        cout<<"\n";
        cout<<"C\t";
        for(auto x : C)
        {
            cout<<x.first<<" "<<x.second<<"\t";
        }
        cout<<"\n";
    }
}