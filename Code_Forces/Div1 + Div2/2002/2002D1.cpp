#include <bits/stdc++.h>
using namespace std;
int checkpr(int n) {
    return 32 - __builtin_clz(n);
}
bool is_dfs_order(int p[], int n) {
    if(p[0]!=1) return false;
    int k = checkpr(n);
    for (int i = 0; i < n; i++) {
        int node_depth = checkpr(p[i]);
        // Check if node is a leaf
        if(p[i]<n/2) {
            // Non-leaf node, determine its children
            int ind1 = i + 1;
            int ind2 = i + (1 << (k - node_depth));

            if (ind1 < n && ind2 < n) { // Ensure indices are within bounds
                if (!((p[ind1] == 2 * p[i] && p[ind2] == 2 * p[i] + 1) ||
                      (p[ind1] == 2 * p[i] + 1 && p[ind2] == 2 * p[i]))) {
                    return false;
                }
            } else {
                return false; // If either index is out of bounds
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int h;
        for (int i = 0; i < n - 1; ++i) {
            cin >> h;
        }
        int p[n];  // Array to store the permutation
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        int x, y;
        bool last = false;
        for (int i = 0; i < q; ++i) {
            cin >> x >> y;
            swap(p[x - 1], p[y - 1]);  // Swapping 0-indexed
            if(last) //the last dfs order was correct
            {
                if(p[x-1]>=n/2 && p[y-1]>=n/2)
                {
                    if(p[x-1]&1) //check if the number that was swapped odd
                    {
                        if(p[x-1]==p[y-1]+1) //for leaf nodes o>e
                        {
                            cout<<"YES\n";
                            last=true;
                        }
                        else
                        {
                            cout<<"NO\n";
                            last =false;
                        }
                    }
                    else //the swapped number is even 
                    {
                        if(p[x-1]==p[y-1]-1) //e<o
                        {
                            cout<<"YES\n";
                            last=true;
                        }
                        else
                        {
                            cout<<"NO\n";
                            last =false;
                        }
                    }
                }
                else
                {
                    cout<<"NO\n";
                    last=false;
                }
            }
            else
            {
                if (is_dfs_order(p, n)) {
                cout << "YES\n";
                last=true;
                } else {
                    cout << "NO\n";
                    last=false;
                }
            }
        }
    }
    return 0;
}