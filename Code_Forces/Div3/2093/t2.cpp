#include<bits/stdc++.h>
using namespace std;
int log_2(int n)
{
    int ans=0;
    int m=n;
    while(n>0)
    {
        ans++;
        n>>=1;
    }
    if(m%(1<<(ans-1))==0) ans--;
    return ans;
}
// we get n <= 2^ans
// so 2^(ans-1) < n <= 2^ans
long long xy_to_d(int x, int y)
{
    if(x==1 && y== 1) return 1;
    if(x==2 && y== 2) return 2;
    if(x==2 && y== 1) return 3;
    if(x==1 && y== 2) return 4;
    int n = log_2(max(x,y));
    int pwr=1<<(n-1);
    if(x > pwr && y > pwr) return (long long)pwr *(long long)pwr + xy_to_d(x-pwr,y-pwr);
    if(x > pwr && y <= pwr) return 2LL*(long long)pwr *(long long)pwr + xy_to_d(x-pwr,y);
    if(x <= pwr && y > pwr) return 3LL*(long long)pwr *(long long)pwr + xy_to_d(x,y-pwr);
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream cout;
    cout.open("out2.txt");
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            cout<<xy_to_d(i+1,j+1)<<"\t";
        }
        cout<<"\n";
    }
    cout.close();
}