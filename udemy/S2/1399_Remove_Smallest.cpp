#include<bits/stdc++.h>
using namespace std;
bool check(int n, vector<int> &a)
{
    int i=0; //tracking index
    n--; //need to run the loop for n-1 times
    while(n--)
    {
        if((a[i+1]-a[i])<2) a.erase(a.begin()+i);
        else i++;
    }
    return(a.size()==1); //sweet sweet return
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    size_t t;
    cin>>t; //testcases
    vector<int> a; //creating the variable array required
    int A; //to take values to the vector<int> as I am a noob can kill?
    int n; //n required
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>A;
            a.push_back(A);
        } //taking values
        sort(a.begin(),a.end()); //sort the guy
        if(check(n,a)) cout<<"YES \n";
        else cout<<"NO \n";
        a.clear();
    }   
}