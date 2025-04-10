#include<bits/stdc++.h>
using namespace std;
bool check(const vector<int> &A, int k, int x) //checks MEX is atleast x
{
    if(x==0) return true;
    int no_of_working_subarrays=0;
    vector<bool> is_present(x,false);
    int store=0;
    for(int a : A) // this traverses the whole array
    {
        if(a<x && !is_present[a]){
            store++;
            is_present[a]=true;
        }
        if(store==x){ //we know x>0
            fill(is_present.begin(), is_present.end(), false); // reset
            no_of_working_subarrays++;
            store=0;//resets store
        }
        if(no_of_working_subarrays>=k) return true;
    }
    return no_of_working_subarrays>=k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    if(check(a,1,9)) cout<<"Y";
    else cout<<"N";
}