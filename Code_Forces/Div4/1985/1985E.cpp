#include<bits/stdc++.h>
using namespace std;
vector<long long> factorList(const long long &k) //debugged,the only problem is for squared numbers
{
    vector<long long> front;
    vector<long long> back;
    for(long long i=1; i*i<=k;i++)
    {
        if(k%i == 0)
        {
            front.push_back(i);
            back.push_back(k/i);
        }
    }
    front.insert(front.end(), back.rbegin(), back.rend());
    return(front);
} //O(sqrt(k))
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //test cases
    cin>>t;
    while (t--)
    {
        long long x,y,z; //yes it is inefficient. Or is it?
        cin>>x>>y>>z;
        long long k;
        cin>>k;
        vector<long long> f = factorList(k); // now I have the sorted list of factors
        //now like a barbarian I can traverse through all the possible dimensions
        long long ways=0;
        long long h;
        for(long long i : f)
        {
            if(i>x) break; //fine
            for(long long j : f)
            {
                long long a = k/i;
                long long b = k/(i*j);
                if(j > y || j > a) break;
                if(b<=z && a%j ==0)
                {
                    h=(x-i+1)*(y-j+1)*(z-b+1);
                    if(h>ways) ways =h;
                }
            }
        }
        cout<<ways<<"\n";
    }
}