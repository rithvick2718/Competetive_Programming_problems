#include<bits/stdc++.h>
using namespace std;
vector<int> arr; //global array
bool compare (int i, int j)
{
    int c=0;
    if(arr[i]==arr[j]) c++;
    if(arr[i+1]==arr[j+1]) c++;
    if(arr[i+2]==arr[j+2]) c++;
    return(c==2);
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
        int h;
        for (size_t i = 0; i < n; i++)
        {
            cin>>h;
            arr.push_back(h);
        }//getting the array
        int s=0;
        for(int i=0; i<n-2; i++)
        {
            for(int j =i+1; j<n-2; j++)
            {
                if(compare(i,j)) s++;
            }
        }
        cout<<s<<"\n";
        arr.clear(); //clearing array for the next use
    }
}