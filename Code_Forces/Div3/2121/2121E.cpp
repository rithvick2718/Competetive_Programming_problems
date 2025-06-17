#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int l,r;
        cin>>l>>r;
        vector<int> L,R;
        while(l>0){
            L.push_back(l%10);
            l/=10;
        }        
        while(r>0){
            R.push_back(r%10);
            r/=10;
        }
        int len = L.size();
        reverse(L.begin(),L.end());
        reverse(R.begin(),R.end());
        int i=0;
        int ans=0;
        bool should_proceed = false;
        for(;i<L.size(); i++){
            if(L[i]==R[i]) ans+=2;
            else if(R[i]-L[i]>1) break;
            else{
                ans+=1;
                i++;
                should_proceed=true;
                break;
            }
        }
        if(should_proceed){
            // cout<<"y";
            int case1=0,case2=0;
            int c1 =i,c2=i;
            while(c1<len){
                if(R[c1]==0){
                    case1++;
                    if(L[c1]==0) case1++;
                    c1++;
                }
                else{
                    if(R[c1]==1 && L[c1]==0) case1++;
                    break;
                }
            }
            while(c2<len){
                if(L[c2]==9){
                    case2++;
                    if(R[c2]==9) case2++;
                    c2++;
                }
                else{
                    if(L[c2]==8 && R[c2]==9) case2++;
                    break;
                }
            }
            ans+=min(case1,case2);
        }
        cout<<ans<<"\n";
    }
}