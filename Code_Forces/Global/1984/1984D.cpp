#include <bits/stdc++.h>
using namespace std;

int count_valid_substrings(const string& s) {
    int n = s.length();
    unordered_set<string> unique_substrings;

    // Collect all unique substrings of s that are not "a"
    for (int i = 0; i < n; ++i) {
        string t;
        for (int j = i; j < n; ++j) {
            t += s[j];
            if (t != "a") {
                unique_substrings.insert(t);
            }
        }
    }

    int count = 0;

    // Check each unique substring to see if it can partition s correctly using DP
    for (const auto& t : unique_substrings) {
        int t_len = t.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            if (!dp[i]) continue;
            if (i + t_len <= n && s.substr(i, t_len) == t) {
                dp[i + t_len] = true;
            }
            if (s[i] == 'a') {
                dp[i + 1] = true;
            }
        }

        if (dp[n]) {
            count++;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<string> test_cases(t);

    for (int i = 0; i < t; ++i) {
        cin >> test_cases[i];
    }

    for (const auto& s : test_cases) {
        cout << count_valid_substrings(s) << "\n";
    }

    return 0;
}
