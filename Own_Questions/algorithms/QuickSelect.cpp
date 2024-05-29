#include<bits/stdc++.h>
using namespace std;
//this is to select the element of order k in an unsorted list
vector<int> nums;
int selectpivot(int l, int r)
{
    int pivot = l + rand()%(r-l);
    return(pivot);
}
int partition(int pivot, int l , int r)
{
    swap(nums[l],nums[pivot]);
    int i=l;
    for(int j = l+1; j<=r; j++)
    {
        if(nums[j]<nums[l])
        {
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[l],nums[i]);
    return(i);
}
int quickselect(int l, int r, int order)
{
    if(l>=r)
    return(nums[l]);
    int pivot = selectpivot(l,r);
    pivot=partition(pivot,l,r);
    if(pivot == order) return(nums[pivot]);
    else if(pivot<order) return quickselect(pivot+1,r,order);
    else return quickselect(l,pivot-1,order);
}
int main()
{
    
}