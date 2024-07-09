#include<bits/stdc++.h>
using namespace std;
void takevectors(vector<vector<long long>> &V, const int &n) //fine
{
    for(auto &v : V)
    {
        v[0]=0;
        for(int i=1; i<n+1; i++)
        {
            cin>>v[i];
            v[i]+=v[i-1];
        }
    }
}
long long divby3(const long long &tot)//debugged
{
    if(tot%3==0) return tot/3;
    return tot/3 +1;
}
vector<pair<long long,long long>> SOLVE(vector<vector<long long>> &V, const long long  &tot, const int &n)
{
    for(int i1 = 0; i1 < 3; i1++)
    {
        for(int i2 =  0; i2 < 3; i2++)
        {
            if(i1!=i2)
            {
                for(int  i3 = 0; i3 < 3; i3++)
                {
                    if(i1!=i3  &&  i2!=i3)
                    {
                        //da code we know  i1, i2, i3 are distinct
                        // I want this to be a function tho
                        auto it = lower_bound(V[i1].begin(),V[i1].end(), divby3(tot));
                        int index1 = distance(V[i1].begin(), it); // this is absolutely fine.
                        if(index1 < n-1) //yes this is appropriate
                        {
                            it = lower_bound(V[i2].begin(),V[i2].end(), V[i2][index1]+ divby3(tot));
                            int index2 = distance(V[i2].begin(),it); //yep this is valid
                            if(tot - V[i3][index2] >= divby3(tot) && index2 < n)
                            {
                                vector<pair<long long,long long>> ans(3);
                                ans[i1]={1,index1};
                                ans[i2]={index1+1,index2};
                                ans[i3]={index2+1,n};
                                return ans;
                            }
                        }
                    }
                }
            }
        }
    }
    vector<pair<long long,long long>> ans(0);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        //code for each testcase
        cin>>n;
        vector<vector<long long>> V(3, vector<long long> (n+1));
        takevectors(V,n);
        long long tot = V[0].back();
        vector<pair<long long,long long>> v =SOLVE(V,tot,n);
        if(v.size()==3)
        {
            for(auto f : v)
            {
                cout<<f.first<<" "<<f.second<<" ";
            }   
        }
        else cout<<-1;
        cout<<"\n";
    }
}