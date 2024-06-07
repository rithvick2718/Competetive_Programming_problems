#include<bits/stdc++.h>
using namespace std;
inline bool compare(const vector<int> &arr, int i, int j) {
    // Compare the three positions
    bool first = (arr[i] == arr[j]);
    bool second = (arr[i + 1] == arr[j + 1]);
    bool third = (arr[i + 2] == arr[j + 2]);

    // Return true if exactly two out of the three are true
    return (first + second + third) == 2;
}//dont think this can be faster
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        vector<int> arr(n);
        for (size_t i = 0; i < n; i++)
        {
            cin>>arr[i];
        }//getting the array
        int s=0;
        for(int i=0; i<n-3; i++)
        {
            for(int j =i+1; j<n-2; j++)
            {
                if(compare(arr,i,j)) s++;
            }
        }
        cout<<s<<"\n";
    }
}