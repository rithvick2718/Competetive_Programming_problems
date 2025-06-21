#include <bits/stdc++.h>
using namespace std;

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
    cout << sumDistancesFromRoot(n, adj) << '\n';
}