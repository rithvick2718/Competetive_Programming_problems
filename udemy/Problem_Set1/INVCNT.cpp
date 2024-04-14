#include<bits/stdc++.h>
using namespace std;
vector<long long int> a;
long long int minv(long long int l, long long int r)
{
    long long int s=0; //it counts the number of inversions
    long long int mid = l+(r-l)/2; 
    vector<long long int> left(mid-l+1);
    for(long long int i=l;i<mid+1;i++)
    {
        left[i-l]=a[i];
    }
    vector<long long int> right(r-mid);
    for(long long int i=mid+1;i<r+1;i++)
    {
        right[i-mid-1]=a[i];
    }
    long long int leftit=0;
    long long int rightit=0;
    while(leftit<left.size() && rightit<right.size())
    {
        if(left[leftit]<=right[rightit])
        {
            a[l+leftit+rightit]=left[leftit];
            leftit++;
            s=s+rightit;
        }
        else
        {
            a[l+leftit+rightit]=right[rightit];
            rightit++;
        }
    }
    while(leftit<left.size())
    {
        a[l+leftit+rightit]=left[leftit];
        leftit++;
        s=s+rightit;
    }
    while(rightit<right.size())
    {
        a[l+leftit+rightit]=right[rightit];
        rightit++;
    }
    return(s);
}
long long int inv(long long int l, long long int r)
{
    if(l>=r) return(0);
    long long int mid= l+(r-l)/2;
    long long int inv1 = inv(l,mid); //calculates the inversions from l to mid
    long long int inv2 = inv(mid+1,r); //calculates the inversions from mid+1 to r
    long long int meinv = minv(l,r); // now l to mid and mid+1 to r is sorted and we find inversions in merging
    return(inv1+inv2+meinv);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    size_t t;
    cin>>t;
    long long int n;
    long long int h; //help variable
    while(t--)
    {
        //the code for each test case
        //so a hlong long int is to use merge sort
        cin>>n;
        for(long long int i=0; i<n;i++)
        {
            cin>>h;
            a.push_back(h);
        }
        cout<<inv(0,(long long int)a.size()-1)<<"\n";
        a.clear();
    }
}