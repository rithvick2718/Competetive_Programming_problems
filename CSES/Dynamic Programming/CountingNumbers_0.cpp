#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> get_digits(ll a){
    vector<int> digits;
    while(a>0LL){
        digits.push_back(a%10LL);
        a/=10LL;
    }
    return digits;
}

ll PWR(ll a, int pwr){
    ll ans = 1LL;
    ll to_multiply=a;
    while(pwr > 0){
        if(pwr&1) ans*=to_multiply;
        to_multiply*=to_multiply;
        pwr>>=1;
    }
    return ans;
}

int between (int low, int high, int exclude){
    int ans =0;
    for(int i=0; i<10; i++){
        if(low<i && i<high && i!=exclude) ans++;
    }
    return ans;
}

bool check(const vector<int> &A){
    bool ans = true;
    if(A.size()==1 || A.empty()) return true;
    int s = A.size();
    int i=0;
    while(A[i]==0) i++;
    for(; i+1<s; i++){
        ans&=(A[i]!=A[i+1]);
    }
    return ans;
}

int main()
{
    ll a,b; // the numbers
    cin>>a>>b; // take them

    vector<int> A = get_digits(a);
    vector<int> B = get_digits(b);

    while(A.size()<B.size()) A.push_back(0);
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end()); //now we have the digits of a,b in order

    // for(auto x : A) cout<<x<<" ";
    // cout<<"\n";
    // for(auto x : B) cout<<x<<" ";
    // cout<<"\n";

    int size = B.size();
    int first = 0;
    ll ans = 0LL;
    if(size == 0) cout<<1;
    else{
        while(B[first]==A[first] && first < size) first++; //  first basically is the position where B[first]!=A[first]
        bool can_continue = (first!=size);
        for(int i=0; i+1<first;i++) can_continue&=(B[i]!=B[i+1]);
        if(can_continue){
            // cout<<"can_con\n";
            // phase 1 nums in between
            int digits_in_between=0;
            if(first!=0){
                digits_in_between = between(A[first],B[first],B[first-1]);
            }
            else{
                digits_in_between = between(A[first],B[first],-1);
            }
            // cout<<digits_in_between<<endl;
            // cout<<PWR(9,size-first-1)<<endl;
            ans+=((ll)digits_in_between)*PWR(9LL,size-first-1);
            // right now in-between nums have been calulated - there is no problem here

            bool continue_big_one = (first==0);
            if(!continue_big_one) continue_big_one|=(B[first-1]!=B[first]);
            if(continue_big_one){
                // cout<<"ex1\n"; - no problem
                for(int s = first+1; s<size; s++){
                    if(s>=2 && B[s-1]==B[s-2]) break;
                    ans+=((ll)between(-1,B[s],B[s-1]))*PWR(9,size-s-1);
                }
            } //np
            bool continue_small_one = (first==0);
            if(!continue_small_one) continue_small_one|=(A[first-1]!=A[first]);
            if(continue_small_one){
                // cout<<"ex2\n";
                int f_nn_0=0;
                while(A[f_nn_0]==0 && f_nn_0 < size) f_nn_0++; //A[f_nn_0] is the first non-zero number of the vector
                if(f_nn_0<=first){
                    // cout<<"t1\n";
                    for(int s = first+1; s<size; s++){
                        if(s>=2 && A[s-2]==A[s-1]) break;
                        ans+=between(A[s],10,A[s-1])*PWR(9,size-s-1);
                    }
                }
                else{
                    // cout<<"t2\n";
                    first++;
                    while(first<f_nn_0){
                        ans+=PWR(9,size-first);
                        first++;
                    }
                    if(first!=size) ans+=between(A[first],10,-1)*PWR(9,size-first-1);
                    for(int s = first+1; s<size; s++){
                        // cout<<s<<"\n";
                        // cout<<A[s]<<" ";
                        if(s>=2 && A[s-1]==A[s-2]) break;
                        ans+=between(A[s],10,A[s-1])*PWR(9,size-s-1);
                    }
                }
            }
        }
        // now we have checked for all numbers in between a and b. now let's check a and b
        if(a==b){
            if(check(A)) ans++;
        }
        else{
            if(check(A)) ans++;
            if(check(B)) ans++;
        }
        
        cout<<ans<<"\n";
    }
}