#include<bits/stdc++.h>
using namespace std;
vector<int> digits(int n){ // as n<=1e9 a.size()<=10
    vector<int> a;
    while(n>0){
        a.push_back(n%10);
        n/=10;
    }
    while(a.size()<10) a.push_back(0);
    return a;
}
int mn(const vector<int> &digits){
    int mn=20;
    int cal =(digits[0]-7)%10;
    if(cal<0) cal+=10;
    mn=min(mn,cal); //fine
    int n=digits.size(); // n=10 I know.
    for(int i=1; i<n; i++){
        int cal =(7-digits[i])%10;
        if(cal<0) cal+=10;
        if(cal<=digits[0]) mn=min(mn,cal);
        else{ // there is a problem here
            bool non_zero_present=false;
            for(int j=1; j<i; j++){
                if(digits[j]!=0){
                    non_zero_present=true;
                    break;
                }
            }
            if(non_zero_present) mn=min(mn,cal);
            else{
                mn=min(mn,cal+1);
                if(digits[i]==8){
                    mn=min(mn,1+digits[0]);
                }
            }
        }
    }
    return mn;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        //code
        int n;
        cin>>n;
        vector<int> dgts = digits(n);
        cout<<mn(dgts)<<"\n";
    }
}