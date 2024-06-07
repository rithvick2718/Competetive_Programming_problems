#include<iostream>
#include<vector>
using namespace std;
void solve (int &x) //taking by reference, that's my boy
{
    vector<int> booles; //need to dynammically allocate, by since array won't be larger than 32 I dont see this as a performance issue. Yet.
    while(x!=0) //do it till our boy x is 0
    {
        if(x&1) //so we have a 1 
        {
            if((x&2)==2) //checks for 11
            {
                booles.push_back(-1); // so I add 1 and sub -1
                x=(x+1)>>1; // see the above comment
            }
            else
            {
                booles.push_back(1); //yeah my boy is fine
                x=x>>1;
            }
        }
        else //this one is fine
        {
            booles.push_back(0);
            x=x>>1;
        }
    }
    int m = booles.size();
    cout<<m<<"\n";
    for(int b : booles)
    {
        cout<<b<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int x;
    while (t--)
    {
        cin>>x;
        solve(x);
    }
}