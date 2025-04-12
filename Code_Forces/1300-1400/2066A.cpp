#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--){
        int n,x;
        cin>>n;
        vector<int> rev_x(n,-1);
        for(int i=0; i<n; i++)
        {
            cin>>x;
            rev_x[x-1]=i+1;
        }
        int not_there=-1;
        for(int i=0; i<n; i++)
        {
            if(rev_x[i]==-1){
                not_there=i+1;
                break;
            }
        }
        int is_there=-1;
        for(int i=0; i<n; i++)
        {
            if(rev_x[i]!=-1){
                is_there=i+1;
                break;
            }
        }
        if(not_there!=-1){
            cout<<"? "<<not_there<<" "<<is_there<<endl;
            int ans;
            cin>>ans;
            if(ans==0) cout<<"! A"<<endl;
            else cout<<"! B"<<endl;
        }
        else{
            int X,Y;
            cout<<"? "<<rev_x[0]<<" "<<rev_x[n-1]<<endl;
            cin>>X;
            cout<<"? "<<rev_x[n-1]<<" "<<rev_x[0]<<endl;
            cin>>Y;
            if(X==Y && X>=n-1) cout<<"! B"<<endl;
            else cout<<"! A"<<endl;
        }
    }
}