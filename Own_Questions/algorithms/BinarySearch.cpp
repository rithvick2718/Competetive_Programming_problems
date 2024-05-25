#include<iostream>
#include<vector>
using namespace std;
vector<int> nums; //this boy is sorted
int binarysearch (int key)
{
    int l=0; //left index
    int r = nums.size()-1; //right index
    int mid = l+(r-l)/2; //middle index
    while(l!=r && l<r)
    {
        if(nums[mid]==key) break;
        else
        {
            if(nums[mid]>key) r=mid-1;
            else l = mid+1;
            mid = l+(r-l)/2;
        }
    }
    if(l==r)
    {
        if(nums[l]==key) return(l);
        else return(-1);
    }
    else
    {
        if(nums[l]==key) return(l);
        else if(nums[r]==key) return(r);
        else return(-1);
    }
}
int main()
{
    int t;
    cin>>t;
    int n;
    int h;
    while(t--)
    {
        
    }
}