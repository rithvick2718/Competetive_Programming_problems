#include<bits/stdc++.h>
using namespace std;
vector<unsigned int> arr;
int findbits (unsigned  int k) //(fine)number of bit in an integer
{
    int m=0;
    while(k!=0)
    {
        k=k>>1;
        m++;
    }
    return(m);
}
bool GETkthbit (unsigned int k, unsigned int num) //(fine)I get the kth bit of a number num
{
    int j = 1<<(k-1);
    j = j & num;
    j= j>>(k-1);
    return((bool) j);
}
int givemezero (int k) //(fine)gives largest number of consecutive 0's
{
    int zerocount=0; //initialising
    int maxum =0; //initialising
    for(unsigned int num : arr)
    {
        if(GETkthbit(k,num)) 
        {
            maxum=max(maxum,zerocount);
            zerocount=0;
        }
        else zerocount++;
    }
    maxum=max(maxum, zerocount);
    return(maxum);
}
int lonely (int mbit)// mbit is the number of bits of the largest element
{
    int maxi=0;
    int h; //helper
    for(unsigned int i=1;i<=mbit; i++) //from bits of 1st place to last
    {
        h=givemezero(i); //I gave (fine)
        if(h!=(int)arr.size()) //this means we reject the case of all the bits in that row as 0
        maxi=max(maxi,givemezero(i)); 
    }
    return(maxi+1);
}
int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin>>t;
    int n;
    while(t--)
    {
        //code here 
        arr.clear();
        std::cin>>n;
        unsigned int h;
        unsigned int maxi=0;
        while(n--)
        {
            std::cin>>h;
            maxi=max(maxi,h);
            arr.push_back(h);
        }// getting array
        int m = findbits(maxi);
        cout<<lonely(m)<<"\n";
    }
}