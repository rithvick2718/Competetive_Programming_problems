#include<bits/stdc++.h>
using namespace std;

int mex_1 (const unordered_set<int> &s);
unordered_set<int> combine(const unordered_set<int> &a,const unordered_set<int> &b);
void first_or_last(deque<pair<int,unordered_set<int>>> &x);
int ans (deque<pair<int,unordered_set<int>>> &x, int m);
bool compare(const pair<int,unordered_set<int>> &a, const pair<int,unordered_set<int>> &b);

int mex_1 (const unordered_set<int> &s)
{
    for(int i=1;; i++) if(s.count(i)==0) return i;
    return -1;
}
unordered_set<int> combine(const unordered_set<int> &a,const unordered_set<int> &b)
{
    unordered_set<int> c;
    for(int x :a) c.insert(x);
    for(int x :b) c.insert(x);
    return c;
}
void first_or_last(deque<pair<int,unordered_set<int>>> &x)
{
    int n =x.size()-1;
    unordered_set<int> first = (combine(x[0].second,x[1].second));
    unordered_set<int> last = (combine(x[n-1].second,x[n].second));
    int first1=mex_1(first);
    int last1=mex_1(last);
    int a=min(x[0].first,last1);
    int b=min(x[n].first,first1);
    if(a>b){ // so combine last 2 elements
        x[n-1].second=last;
        x[n-1].first=last1;
        x.pop_back();
    }
    else{
        x[1].second=first;
        x[1].first=first1;
        x.pop_front();
    }
    return;
}
int ans (deque<pair<int,unordered_set<int>>> &x, int m)
{
    if(m==0) return (*min_element(x.begin(),x.end(),compare)).first;
    while(m--)
    {
        auto it = min_element(x.begin(),x.end(),compare);
        if(it == x.begin()){
            x[1].second = (combine(x[0].second,x[1].second));
            x[1].first = mex_1(x[1].second);
            x.pop_front();
        }
        else if(it == x.end()-1){
            x[x.size()-2].second=combine(x[x.size()-1].second,x[x.size()-2].second);
            x[x.size()-2].first=mex_1(x[x.size()-2].second);
            x.pop_back();
        }
        else{
            // it + 1 vs it - 1
            unordered_set<int> A =combine((*(it-1)).second,(*it).second);
            unordered_set<int> B =combine((*(it+1)).second,(*it).second);
            int a = mex_1(A);
            int b = mex_1(B);
            int a1 =min(a,(*(it+1)).first);
            int b1 =min(b,(*(it-1)).first);
            if(a1>b1)
            {
                (*(it-1)).second= A;
                (*(it-1)).first=a;
                x.erase(it);
            }
            else
            {
                (*(it+1)).second= B;
                (*(it+1)).first=b;
                x.erase(it);
            }
        }
    }
    return (*min_element(x.begin(),x.end(),compare)).first;
}
bool compare(const pair<int,unordered_set<int>> &a, const pair<int,unordered_set<int>> &b)
{
    return a.first <b.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,k,a;
        cin>>n>>k;
        deque<pair<int,unordered_set<int>>> x;
        x.push_back({1,{}});
        for (int i = 0; i < n; i++)
        {
            cin>>a;
            if(a!=0) x.back().second.insert(a);
            else{
                x.back().first=mex_1(x.back().second);
                x.push_back({1,{}});
            }
        }
        x.back().first=mex_1(x.back().second);
        if(x.size()-1<k) cout<<0<<"\n";
        else{
            first_or_last(x);
            int to_remove=x.size()-k;
            cout<<ans(x,to_remove)<<"\n";
        }
    }
}