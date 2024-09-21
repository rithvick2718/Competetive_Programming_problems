#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; //testcases
    cin>>t;
    while(t--)
    {
        //code
        int robin_gold =0;
        int n,k;
        cin>>n>>k;
        int a;
        int number=0;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            if(a>=k)
            {
                robin_gold+=a;
            }
            else if(a==0 && robin_gold>0)
            {
                robin_gold--;
                number++;
            }
        }
        cout<<number<<"\n";
    }
}