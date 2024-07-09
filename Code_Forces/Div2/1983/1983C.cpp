#include<bits/stdc++.h>
using namespace std;
void takevectors(vector<vector<int>> &V, const int &n) //fine
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
int divby3(const int &tot)//debugged
{
    if(tot%3==0) return tot/3;
    return tot/3 +1;
}
vector<pair<int,int>> SOLVE(vector<vector<int>> &V, const int  &tot, const int &n)
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
                    }
                }
            }
        }
    }
    vector<pair<int,int>> ans(0);
    return ans;
}
void debug (vector<vector<int>> &V)
{
    char name = 'A';
    for (auto a : V)
    {
        cout<<name<<" : ";
        for(auto x : a)
        {
            cout<<x<<" ";
        }
        name ++;
        cout<<"\n";
    }
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
        vector<vector<int>> V(3, vector<int> (n+1));
        takevectors(V,n);
        int tot = V[0][n-1];
        vector<pair<int,int>> v =SOLVE(V,tot,n);
        if(v.size()==3)
        {
            for(auto f : v)
            {
                cout<<f.first<<" "<<f.second<<" ";
            }   
        }
        else cout<<-1;
        cout<<"\n";
        debug(V);
    }
}