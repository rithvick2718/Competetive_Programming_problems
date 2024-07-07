#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin >> t;
    while (t--)
    {
        //code
        cin>>n;
        int a[n];
        int b[n];
        for(int i=0; i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n;i++)
        {
            cin>>b[i];
        }
        int ascore=0,bscore=0;
        int pos=0,neg =0;
        for(int i=0; i<n;i++)
        {
            if(a[i]==b[i])
            {
                if(a[i]==1) pos++;
                else if(a[i]==-1) neg++;
            }
            else
            {
                if(a[i]>b[i]) ascore+=a[i];
                else bscore+=b[i];
            } //this is undisputable
        }
        //now we have pos, neg, ascore, bscore
        while(pos>0)
        {
            if(ascore>bscore) bscore++;
            else ascore++;
            pos--;
        }
        while(neg>0)
        {
            if(ascore<bscore) bscore--;
            else ascore--;
            neg--;
        }
        cout<<min(ascore,bscore)<<"\n";
    }
}