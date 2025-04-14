#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> getAllSubsetsOfLengthN(const vector<ll>& arr);
void generateCombinations(const vector<ll>& arr, int n, int start,
                           vector<ll>& current,
                           vector<vector<ll>>& result);
ll partial_sum(vector<ll> S);
void print_order(const vector<ll> &b, const vector<ll> &res, bool order);
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
        vector<ll> b(2*n);
        unordered_set<ll> s; // to check if the element is there or not
        ll sum=0;
        for(int i=0; i<2*n; i++) {
            cin>>b[i]; //taking in
            sum+=b[i];
            s.insert(b[i]);
        } // all b[i] are unique
        vector<vector<ll>> result =getAllSubsetsOfLengthN(b); // the ultimate generation - Gen Z
        // cout<<result.size()<<"\n";
        // for(auto R: result){
        //     for(auto r : R) cout<<r<<" ";
        //     cout<<"\n";
        // }
        vector<ll> to_p; // to catch the array I need to choose
        ll cal=0;
        for(auto R : result){
            cal=2*partial_sum(R)-sum; // understandable
            cal=abs(cal);
            if(s.count(cal)==0 && cal!=0){
                to_p=R;
                break; //fair
            }
        }// so to_p is non empty if and only if I found a cal and this subset is good
        if(!to_p.empty()){
            cal=2*partial_sum(to_p)-sum;
            if(cal>0){
                cout<<cal<<" ";
                print_order(b,to_p,1);
                cout<<"\n";
            }
            else{
                cout<<-cal<<" ";
                print_order(b,to_p,0);
                cout<<"\n";
            }
        } //perfect!
        else{
            ll x,rr; // thy hardeth part tho
            // now our lost number is in addition side.
            for(auto R : result){
                ll rsum=partial_sum(R); // understandable
                bool to_break=false;
                for(auto r : R){
                    x=2*r+sum-2*rsum;
                    if(x>0 && s.count(x)==0){
                        to_break=true; // now I found a worthy x.
                        to_p=R; // I store to_p. this is reused 
                        rr=r; // so it's like rr =  x -() + (element in to_p that is not r) -() + ...
                    }
                }
                if(to_break) break;
            }
            // now I have to_p x and rr
            cout<<rr<<" "<<x<<" ";
            // so the idea is I will make vector<ll> c(2n-1) and at 0, 2 etc all the elements not in to_p will be there
            vector<ll> NOT_USED_A; // i am not able to track the variables I used...
            vector<ll> NOT_USED_B;
            unordered_set TO_P(to_p.begin(),to_p.end());
            for(int i=0; i<2*n; i++){
                if(TO_P.count(b[i])==0) NOT_USED_B.push_back(b[i]);
            }
            TO_P.erase(rr);
            for(auto j : TO_P) NOT_USED_A.push_back(j);
            for(int i=0; i<2*n-1; i++){
                if(i&1) cout<<NOT_USED_A[i/2]<<" ";
                else cout<<NOT_USED_B[i/2]<<" ";
            }
            cout<<"\n";
        }
    }
}
void print_order(const vector<ll> &b, const vector<ll> &res, bool order)
{
    int n=res.size();
    vector<ll> c(2*n);
    for(int i=0; i<n; i++)
        c[2*i]=res[i];
    vector<ll> d;
    unordered_set p(res.begin(),res.end());
    for(auto bb : b)
        if(p.count(bb)==0) d.push_back(bb);
    for(int i=0; i<n; i++)
        c[2*i +1]=d[i];
    if(order){
        for(auto cc : c) cout<<cc<<" ";
    }
    else{
        for(int i=2*n-1; i>=0; i--) cout<<c[i]<<" ";
    }
    return;
}
ll partial_sum(vector<ll> S){
    ll sum =0;
    for(auto s : S) sum+=s;
    return sum;
}
void generateCombinations(const vector<ll>& arr, int n, int start,
                          vector<ll>& current,
                          vector<vector<ll>>& result) {
    if (current.size() == n) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < arr.size(); ++i) {
        current.push_back(arr[i]);
        generateCombinations(arr, n, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<ll>> getAllSubsetsOfLengthN(const vector<ll>& arr) {
    int n = arr.size() / 2;
    vector<vector<ll>> result;
    vector<ll> current;
    generateCombinations(arr, n, 0, current, result);
    return result;
}