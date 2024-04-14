//this is my attempt at binary search
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> sor;
    for(int i=0; i< 100; i++)
    {
        sor.push_back(2*i);
    }
    int key = 47;
    int low =0;
    int high =(int) sor.size();
    while(low<high)
    {
        int mid =low+(high-low)/2;
        if(sor[mid]<key)
        {
            low =mid+1;
        }
        else 
        {
            high=mid;
        }
    }
    if(sor[low]==key)
    cout<<"Found it at "<<low;
    else
    cout<<"not found must be placed at "<<low;
    return 0;
 }