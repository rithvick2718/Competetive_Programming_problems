#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> a(9,vector<bool> (8,true));
vector<vector<bool>> b(9,vector<bool> (8,true));
bool check_diagnol(int i, int j)
{
    int x =i;
    int y =j;
    for(int m=-1; m<=1; m+=2){
        for(int n=-1; n<=1; n+=2){
            x=i;
            y=j;
            while(x>=0 && y>=0 && x<=7 && y<=7)
            {
                if(!b[x][y]) return false;
                x+=m;
                y+=n;
            }
        }
    }
    return true;
}
int solve(int start)
{
    if(start==8) return 1;
    int ans=0;
    for(int i=0; i<8; i++)
    {
        if(a[8][i]&&a[start][i]&&check_diagnol(start,i)) //so [start][i] is where we want to place our queen
        {
            b[start][i]=false;
            a[8][i]=false;
            ans+=solve(start+1);
            a[8][i]=true;
            b[start][i]=true;
        }
    }
    return(ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cin>>c;
            if(c=='*') a[i][j]=false;
        }
    } // taking the input
    cout<<solve(0);
}
//finally there can be optimization but this is the base bone code that passed all the test cases
//O(n!) but n=8 and 8!=40320 sooo you now see