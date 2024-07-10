#include<bits/stdc++.h>
using namespace std;

// Function to read input for a 2D vector and convert chars to ints
void take(vector<vector<int>> &a, const int &n, const int &m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';  // Convert char to int
        }
    }
}

int main() {
    ios::sync_with_stdio(false);  // Disable synchronization between C and C++ standard streams
    cin.tie(NULL);  // Untie cin from cout, allowing cin to work independently for faster input

    int t;  // Number of test cases
    cin >> t;
    while(t--) {
        int n, m;  // Dimensions of the matrices
        cin >> n >> m;
        
        // Initialize two n x m matrices
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));
        
        // Read input for both matrices
        take(a, n, m);
        take(b, n, m);

        int rsuma = 0, rsumb = 0;  // Variables to store row sums modulo 3 for matrices a and b
        int csuma = 0, csumb = 0;  // Variables to store column sums modulo 3 for matrices a and b
        bool ans = true;  // Boolean flag to store the result (true if row and column sums match, false otherwise)

        // Calculate row sums modulo 3 and compare
        for(int i = 0; i < n && ans; i++) {
            rsuma = 0;
            rsumb = 0;
            for(int j = 0; j < m; j++) {
                rsuma = (rsuma + a[i][j]) % 3;  // Sum elements of the i-th row of matrix a modulo 3
                rsumb = (rsumb + b[i][j]) % 3;  // Sum elements of the i-th row of matrix b modulo 3
            }
            if(rsuma != rsumb) ans = false;  // If row sums modulo 3 do not match, set ans to false
        }

        // Calculate column sums modulo 3 and compare
        for(int i = 0; i < m && ans; i++) {
            csuma = 0;
            csumb = 0;
            for(int j = 0; j < n; j++) {
                csuma = (csuma + a[j][i]) % 3;  // Sum elements of the i-th column of matrix a modulo 3
                csumb = (csumb + b[j][i]) % 3;  // Sum elements of the i-th column of matrix b modulo 3
            }
            if(csuma != csumb) ans = false;  // If column sums modulo 3 do not match, set ans to false
        }

        // Output result based on the value of ans
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}