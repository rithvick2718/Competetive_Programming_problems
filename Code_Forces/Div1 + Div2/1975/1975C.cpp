#include<bits/stdc++.h>
using namespace std;
vector<int> arr;//array
int maxmed(int index)
{
    int n = arr.size();
    if (index == 0) {
        return (arr[index] + arr[index + 1]) / 2;
    } else if (index == n - 1) {
        return (arr[index] + arr[index - 1]) / 2;
    } else {
        return max({arr[index], (arr[index] + arr[index + 1]) / 2, (arr[index] + arr[index - 1]) / 2});
    }
}
int main()
{
    int t; //testcases
    cin>>t;
    int n; //array size
    int h; //helping var
    while(t--) //code for each test case
    {
        cin>>n;
        int m=n;
        while(m--)
        {
            cin>>h;
            arr.push_back(h);
        }//getting the array the largest element and it's index
        int max =std::numeric_limits<int>::min();
        for(int i=0;i<arr.size();i++)
        {
            if(max<maxmed(i)) max= maxmed(i);
        }
        cout<<max<<"\n";
        arr.clear();
    }
}