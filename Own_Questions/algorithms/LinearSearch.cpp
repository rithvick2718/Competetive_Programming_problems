#include<iostream>
#include<vector>
using namespace std;
vector<int> nums;
int linearsearch(int key)
{
    for(int i=0; i< nums.size(); i++)
    {
        if(nums[i]==key) return(i);
    }
    return(-1);
}
int main()
{
    int n;
    cin>>n;
    int h;
    while(n--)
    {
        cin>>h;
        nums.push_back(h);
    }
    cin>>h;
    int k = linearsearch(h);
    if(k!=-1) cout<<h<<" found at " <<k+1;
    else cout<<"Not found";
}