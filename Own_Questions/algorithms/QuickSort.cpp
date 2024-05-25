#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> nums; // global variable to make things easier
int selectpivot(int l, int r)
{
    return(l+rand()%(r-l));
}
int partition(int pivot, int l, int r)
{
    swap(nums[l],nums[pivot]);
    int i=l;
    for(int j=l+1;j<=r;j++)
    {
        if(nums[j]<nums[l])
        {
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i],nums[l]);
    return(i);
}
void quicksort(int l, int r)
{
    if(l>=r) return;
    int pivot = selectpivot(l,r);
    pivot=partition(pivot,l,r);
    quicksort(l,pivot);
    quicksort(pivot+1,r);
}
int main()
{
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        nums.push_back(n);
    }
    quicksort(0,nums.size());
    for(auto k : nums)
    {
        cout<<k<<" ";
    }
}