#include<bits/stdc++.h>
using namespace std;
vector<int> V; //global array of Vi
int n; // the n
vector<int> S; //thy s
unsigned int countSetBits(int n)
{
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
int iterpow(const int &m, const int &p) //this is fine
{
    int x=p; // for bit representation
    int y =m; // even powers of m
    int r=1; // actual value of n^p
    do
    {
        if(x%2==1)
        {
            r=r*y;
        }
        y=y*y;
        x=x/2;
    }while(x!=0);
    return(r);
}
bool check( int s,  int index) //fine, this checks if s satisfies the condition for each v
{
    int u=(index+1)&s; //since we do 0th index
    // the purpose is that, let us say s and index have jth bit equal to 1 then it takes jth bit as one else 0
    int k=countSetBits(u); //this is |S intersection T|
    return((bool)((V[index]>>k)&1));
}
bool work (int s)//checks the condition for all the elements of array
{
    for (int i = 0; i < V.size(); i++)
    {
        if(!check(s,i)) return(false);
    }
    return(true);
}
void solve()
{
    for(int s=0; s<iterpow(2,n); s++)
    {
        if(work(s)) S.push_back(s);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int two =2;
    int m =iterpow(two,n)-1;
    int k;
    while(m--)
    {
        cin>>k;
        V.push_back(k);
    } //now we have vis, yes it is taking vectors;
    solve();
    cout<<S.size()<<"\n";
    for(auto s : S)
    {
        cout<<s<<"\n";
    }
}