#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k=1;
    cin>>n;
    vector<int>a(n,false);
    int dead=0; //dead is initally set to killer
    int l;
    for(int i=0; i<n-1 ;i++)
    {
        // the current value of dead is the killer.
        // a[dead]=false
        l=0;
        while(l<k)
        {
            dead=(dead+1)%n;
            if(!a[dead]){
                l++;
            }
        }
        cout<<dead+1<<" ";
        a[dead]=true;
        while(a[dead]){
            dead=(dead+1)%n;
        }
    }
    cout<<dead+1;
}