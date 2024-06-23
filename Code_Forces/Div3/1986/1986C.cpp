#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        string s;
        cin >> s;
        
        vector<int> ind(m);
        for (int i = 0; i < m; ++i) {
            cin >> ind[i];
            ind[i]--; // Convert to 0-based index
        }
        
        string c;
        cin >> c;
        
        // Create pairs of (index, character) and sort by character for smallest lexicographical result
        vector<pair<int, char>> updates;
        for (int i = 0; i < m; ++i) {
            updates.push_back({ind[i], c[i]});
        }
        
        sort(updates.begin(), updates.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.second < b.second; // Sort by character in c
        });
        
        // Apply updates to the string s to get the lexicographically smallest result
        vector<char> res(s.begin(), s.end());
        for (auto& update : updates) {
            int index = update.first;
            char character = update.second;
            res[index] = character;
        }
        
        // Convert result back to string
        string result(res.begin(), res.end());
        
        // Output the result for this test case
        cout << result << "\n";
    }
    
    return 0;
}
