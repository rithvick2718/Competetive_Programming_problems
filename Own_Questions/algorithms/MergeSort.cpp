#include<iostream>
#include<vector>
using namespace std;
vector<int> nums;
void merge(int l,int r)
{
    if(l>=r) return;
    int mid = l+(r-l)/2; //this is a safer way to calculate (l+r)/2 since there is a chance l+r can overflow
    vector<int> left(mid-l+1); // the left side is sorted
    vector<int> right(r-mid); // the right side is also sorted
    for(int i=0; i< mid- l +1; i++) left[i]=nums[l+i]; //so I am copying this
    for(int i=0; i< r-mid; i++) right[i]=nums[mid+1+i]; //so I am copying this
    //now yee shall merge (as the function says)
    int lin=0, rin=0; //left index and right index
    while(lin<(int)left.size() && rin<(int)right.size())
    {
        if(left[lin]<=right[rin])
        {
            nums[l+lin+rin]=left[lin];
            lin++;
        }
        else
        {
            nums[l+lin+rin]=right[rin];
            rin++;
        }
    } //now after this we may have lin or rin not equal to mid-l+1 or r-mid
    while(lin<left.size())
    {
        nums[l+lin+rin]=left[lin];
        lin++;
    }
     while(rin<right.size())
    {
        nums[l+lin+rin]=right[rin];
        rin++;
    }
}
void mergesort(int l, int r)
{
    if(l>=r) return;
    int mid = l+(r-l)/2; //this is a safer way to calculate (l+r)/2 since there is a chance l+r can overflow
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,r);
}
int main()
{
    int n;
    cin>>n;
    int m=n;
    int k;
    while(m--)
    {
        cin>>k;
        nums.push_back(k);
    }
    mergesort(0,n-1);
    for(auto k : nums)
    {
        cout<<k<<" ";
    }
}