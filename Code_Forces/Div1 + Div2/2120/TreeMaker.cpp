#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll binserK (ll n, ll m);
void tree_maker();
void taketree_and_output();
long long sumDistancesFromRoot(int n, vector<vector<int>>& adj);

ll binserK(ll n, ll m) {
    if(m == n-1) return 1;
    if( m == n*(n-1)/2 ) return n-1;
    ll lo = 0, hi = n, ans = -1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll lhs = (ll)mid * n - (ll)mid * (mid + 1) / 2;
        ll rhs = (ll)(mid + 1) * n
                     - (ll)(mid + 1) * (mid + 2) / 2;
        if (lhs <= m && m < rhs) {
            ans = mid;
            break;
        } else if (m < lhs) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
void tree_maker(){ //node is 1.
    ifstream cin;
    cin.open("input.txt");
    ofstream cout;
    cout.open("tree.txt");
    ll n,m;
    cin>>n>>m;
    if(m<n-1 || m > (n*(n-1))/2 ) cout<<-1<<"\n";
    else{
        ll k;
        k = binserK(n,m);
        cout<<n<<"\n";
        ll p = m + ((k*(k+1))/2LL) - n*k;
        for(ll i =1LL; i<=k; i++){
            cout<<i<<" "<<i+1LL<<"\n";
        }
        ll i = k+2;
        for(ll rep = 0; rep < n-k-1-p; rep++) cout<<k<<" "<<i+rep<<"\n";
        i = n-p+1;
        for(ll rep = 0; rep < p; rep++) cout<<k+1<<" "<<i+rep<<"\n";            
    }
}
long long sumDistancesFromRoot(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);
    long long total = 0;

    function<void(int, int)> dfs = [&](int node, int depth) {
        visited[node] = true;
        total += depth;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, depth + 1);
            }
        }
    };

    dfs(1, 0); // root is node 1
    return total;
}
void taketree_and_output() {
    int n;
    ifstream cin;
    cin.open("tree.txt");
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ofstream cout;
    cout.open("output.txt");
    cout <<sumDistancesFromRoot(n, adj) << '\n';
}
int main()
{
    tree_maker(); // this basically my solution to 2120C assuming d(v) was distance
    taketree_and_output(); // this takes tree and outputs distance from node
}