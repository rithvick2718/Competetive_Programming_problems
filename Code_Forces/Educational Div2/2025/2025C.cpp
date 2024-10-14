#include<bits/stdc++.h>
using namespace std;
std::vector<std::pair<int, int>> findContinuousRanges(std::map<int, int>& mp) {
    std::vector<std::pair<int, int>> result;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        int x = it->first;
        // Check if mp[x-1] is 0 or does not exist
        if (mp.find(x - 1) == mp.end() || mp[x - 1] == 0) {
            int n = 0;
            while (mp.find(x + n) != mp.end() && mp[x + n] != 0) {
                ++n;
            }
            if (mp.find(x + n) == mp.end() || mp[x + n] == 0) {
                result.push_back({x, n}); // n-1 since range ends at x+n-1
            }
        }
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,k;
    while(t--)
    {
        cin>>n>>k;
        int a;
        map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            mp[a]++;
        } // this is still valid
        vector<pair<int,int>> cont_sub=findContinuousRanges(mp);
        int new_sum=0;
        int mx_sum=-1;
        for(auto c : cont_sub)
        {
            if(c.second <= k) {
                new_sum = 0;
                for(int i = c.first; i < c.first + c.second; i++) {
                    new_sum += mp[i];  // Sum up all elements in the subsequence
                }
                mx_sum = max(new_sum, mx_sum);
            } else {
                // Handle the case where the subsequence length exceeds k
                new_sum = 0;
                int i = c.first;
                // First window of size k
                for(int j = i; j < i + k; j++) {
                    new_sum += mp[j];
                }
                mx_sum = max(new_sum, mx_sum);
                for(i = c.first + k; i <= c.first + c.second; i++) {
                    new_sum += mp[i];           // Include next element in the window
                    new_sum -= mp[i - k];       // Remove the element that slid out of the window
                    mx_sum = max(new_sum, mx_sum);  // Update max sum
                }
            }
        }
        cout<<mx_sum<<"\n";
    }
}