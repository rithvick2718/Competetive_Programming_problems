#include<bits/stdc++.h>
using namespace std;
int special_binary_search(int k)
{
    if (k == 0) return 0;
    int low = 0, high = 500, mid;
    while (low < high)  
    {
        mid = (low + high + 1) / 2;  // Ensure rounding up
        if ((mid) * (mid - 1) <= 2 * k) 
            low = mid;  // Move low up to get the greatest valid `n`
        else 
            high = mid - 1;  // Reduce the search space
    }
    return low;  // `low` holds the maximum valid `n`
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int m;
        int x = -1000, y=0;
        vector<int> M;
        int vertex=0;
        while(k>0)
        {
            m=special_binary_search(k);
            k-=((m)*(m-1))/2;
            vertex+=m;
            M.push_back(m);
        }
        cout<<vertex<<"\n";
        for(auto n : M)
        {
            for(int i=0; i<n; i++)
            {
            cout<<x<<" "<<y<<"\n";
            x++;
            }
            y++;
        }
    }
}