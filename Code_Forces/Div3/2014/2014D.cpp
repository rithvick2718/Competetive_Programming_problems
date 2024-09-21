#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; // test cases
    cin >> t;
    while(t--)
    {
        int n, d, k;
        cin >> n >> d >> k;
        int jobs[n - d + 1] ={};
        for(int i = 0; i < k; i++)
        {
            int l, r;
            cin>>l>> r;
            if (l - d >= 0) jobs[l - d]++;            
            if (r < n - d + 1) jobs[r]--;
        }
        for(int i = 1; i < n - d + 1; i++)
        {
            jobs[i] += jobs[i - 1];
        }
        cout<< max_element(jobs,jobs+n-d+1)-jobs+1 << " " << min_element(jobs,jobs+n-d+1)-jobs+1 <<"\n";
    }
    return 0;
}