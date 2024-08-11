#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    long long k;
    while(t--)
    {
        cin>>n>>k;
        vector<pair<long long,bool>> tab(n);
        long long h1;
        for(int i=0; i<n; i++)//geting values
        {
            cin>>h1;
            tab[i].first=h1;
        }
        int h2;
        for(int i=0; i<n ;i++)//getting values
        {
            cin>>h2;
            if(h2&1) tab[i].second =true;
            else tab[i].second =false;
        }
        sort(tab.begin(),tab.end());
        if(tab.back().second) cout<<tab[(n/2)-1].first+tab.back().first+k<<"\n"; //the easy part
        else //the hard part
        {
            long long mx=0;
            int l_index=n-1;
            for(; l_index>=0;l_index--)
            {
                if(tab[l_index].second) break;
            }
            if(l_index >= 0 && tab[l_index].first+k>=tab.back().first)
            {
                if(l_index>(n/2)-1) mx=max(mx,tab[(n/2)-1].first+tab[l_index].first+k);
                else mx=max(mx,(tab[(n/2)].first+tab[l_index].first+k));
            }
            //now we increase median
            while(k>0)
            {
                int i= n/2 -1;
                for( ; i>=0 ; i--)
                {
                    if(tab[i].second) // this finds the first element we can increase
                    {
                        if(i==(n/2)-1) //if the median can be increased increase till it can be greater than equal to the element on the right
                        {
                            while(k>0 && tab[i].first<=tab[i+1].first)
                            {
                                long long diff= tab[i+1].first-tab[i].first+1;
                                tab[i].first+=min(k,diff);
                                k-=min(k,diff);
                            }
                            while(tab[i].first>tab[i+1].first && i<n-1)
                            {
                                swap(tab[i],tab[i+1]);
                                i++;
                            }
                            //now tab[(n/2)-1].first =tab[(n/2)-1].first || now tab[(n/2)-1].first =tab[(n/2)-1].first+1
                            // if(tab[(n/2)-1].second && tab[(n/2)].second && n/2 +1 <n)
                            // {
                            //     while(k>0 && tab[(n/2)].first <= tab[(n/2)+1].first)
                            //     {
                            //         long long inc =min(k/2,tab[(n/2)+1].first-tab[(n/2)].first+1);
                            //         tab[(n/2)-1].first+=inc;
                            //         tab[(n/2)].first+=inc;
                            //         k-=((long long) 2)*inc;
                            //         swap(tab[n/2+1],tab[n/2-1]);
                            //         swap(tab[n/2],tab[n/2+1]);
                            //     }
                            // }
                        }
                        else //now whatever element that is there(that is just less than median) that we can increase, increase it 
                        {
                            while(k>0 && tab[i].first<=tab[n/2 -1].first)
                            {
                                long long diff = tab[n/2 -1].first-tab[i].first+1;
                                tab[i].first+=min(k,diff);
                                k-=min(k,diff);
                            }
                            while(tab[i].first>tab[i+1].first && i<n-1)
                            {
                                swap(tab[i],tab[i+1]);
                                i++;
                            }
                        }
                        break; //and once we find it we break the loop
                    }
                }
                if(i==-1) break; //this means all the elements from index 0 to n/2 -1 cannot be increased
            }
            mx=max(mx,tab[(n/2)-1].first+tab.back().first);
            cout<<mx<<"\n";
        }
    }
}