#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    size_t t;
    string bin;
    int s=0; //help variable
    int es=0; //even sum
    int os =0; //odd sum
    vector<int> num; //the array
    cin>>t;
    while(t--)
    {
        //the code for each test case
        //my idea is that note down the number of 1's then sort that 
        //and split into two sums and the larger is the answer
        cin>>bin;
        for(int i=0;i<bin.size();i++)
        {
            if(bin[i]=='0')
            {
                if(s!=0) num.push_back(s);
                s=0;
            }
            if(bin[i]=='1')
            {
                s++;
            }
        }
        if(s!=0) num.push_back(s); //the array is created
        sort(num.begin(),num.end()); //sort it
        for(int i=0; i<num.size(); i++)
        {
            if(i%2==0) es=es+num[i];
            else os=os+num[i];
        }
        if(es>os) cout<<es<<"\n";
        else cout<<os<<"\n";
        s=0;
        es=0;
        os=0;
        bin.clear();
        num.clear(); //clearing them for next test case
    }
}