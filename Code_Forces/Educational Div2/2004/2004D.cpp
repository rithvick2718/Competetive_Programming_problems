#include<bits/stdc++.h>
using namespace std;
map<string,int> dict;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    dict["BG"]=0; //5
    dict["BR"]=1; //4
    dict["BY"]=2; //3
    dict["GR"]=3; //2
    dict["GY"]=4; //1
    dict["RY"]=5; //0
    int t;
    cin>>t;
    int n,q;
    while(t--)
    {
        cin>>n>>q;
        string c[n];
        for(int i=0; i<n; i++)
        {
            cin>>c[i];
        }
        int x,y;
        for(int i=0; i<q; i++)
        {
            cin>>x>>y;
            if(dict[c[x-1]]+dict[c[y-1]]!=5) cout<<abs(x-y)<<"\n"; //fine
            else
            {
                //firstly search for any city in between
                bool has_swapped=false;
                if(x>y){
                    swap(x,y);
                    has_swapped=true;
                }  //x<y

                bool city_found=false;
                for(int i=x-1; i<y; i++)
                {
                    if(dict[c[i]]!=dict[c[x-1]] && dict[c[i]]!=dict[c[y-1]])
                    {
                        city_found=true;
                        break;
                    }
                }

                if(city_found) cout<<(y-x)<<"\n"; //fine!

                else
                {
                    if(has_swapped) swap(x,y);
                    int ans =INT_MAX;
                    for(int i=x-1; i>=0; i--)
                    {
                        if(dict[c[i]]!=dict[c[x-1]] && dict[c[i]]!=dict[c[y-1]] )
                        {
                            ans= min(ans, (x-(i+1))+(y-(i+1)));
                        }
                    }
                    for(int i=y-1; i<n; i++)
                    {
                        if(dict[c[i]]!=dict[c[x-1]] && dict[c[i]]!=dict[c[y-1]] )
                        {
                            ans= min(ans, (i+1-x) + (i+1-y));
                        }
                    }
                    if(ans==INT_MAX) cout<<-1<<"\n";
                    else cout<<ans<<"\n";
                }

            }
        }
    }
}