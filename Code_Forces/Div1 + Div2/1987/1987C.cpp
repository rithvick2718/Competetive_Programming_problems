#include <bits/stdc++.h>
using namespace std;
void nsecondoperation(vector<int> &h, int n)
{
    int size =h.size();
    while(n--)
    {
        for(int i=0; i<size-1; i++)
        {
            if(h[i]>h[i+1]) h[i]=max(0,h[i]-1);
        }
        h[size-1]=max(0,h[size-1]-1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        int seconds = 0;
        auto max_it = std::max_element(h.begin(), h.end());
        int max_value = *max_it;
        while(max_value!=0)
        {
            seconds+=max_value;
            nsecondoperation(h,max_value);
            max_it = std::max_element(h.begin(), h.end());
            max_value = *max_it;
        }      
        cout << seconds << "\n";
    }
    
    return 0;
}