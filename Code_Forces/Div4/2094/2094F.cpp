#include<bits/stdc++.h>
using namespace std;
int gcd (int n, int m)
{
    if(m>=n)
    {
        int r;
        while (n!=0)
        {
            r=m%n;
            m=n;
            n=r;
        }
        return(m);
    }
    else
    return gcd(m,n);
}
int find_a(int A, int B, int k)
{
    for(int a=2; a<=A; a++)
    {
        if((A%a==0) && (B%(k/a)==0)) return a; 
    }
    return A;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    int n,m,k;
    while(tt--)
    {
        cin>>n>>m>>k;
        int A=gcd(n,k);
        int B =gcd(m,k);
        if(A==1){ // this means k|m so B=k
            for(int i=0; i<n; i++){
                int s= i%k;
                s++;
                for(int j=0; j<m; j++){
                    cout<<s<<" ";
                    s++;
                    if(s>k) s-=k;
                }
                cout<<"\n";
            }
        }
        else if( B==1 ){ // this means k|n so A=k
            for(int i=0; i<n; i++){
                int s= i%k;
                s++;
                for(int j=0; j<m; j++){
                    cout<<s<<" ";
                    s++;
                    if(s>k) s-=k;
                }
                cout<<"\n";
            }
        }
        else{
            int a =find_a(A,B,k);
            int  b =k/a;
            if(a==1 || b==1){
                for(int i=0; i<n; i++){
                    int s= i%k;
                    s++;
                    for(int j=0; j<m; j++){
                        cout<<s<<" ";
                        s++;
                        if(s>k) s-=k;
                    }
                    cout<<"\n";
                }
            }
            else{
                vector<vector<int>> t(b,vector<int>(a));
                int fill=1;
                for(int i=0; i<b; i++)
                {
                    for(int j=0; j<a; j++){
                        t[i][j]=fill;
                        fill++;
                    }
                }
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        cout<<t[j%b][i%a]<<" ";
                    }
                    cout<<"\n";
                }
            }
        }
    }
}