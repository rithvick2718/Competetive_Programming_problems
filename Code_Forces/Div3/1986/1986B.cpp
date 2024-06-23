#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        
        // Read the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        int run =10;
        while(run--)
        {
            // Process the matrix (excluding the boundaries)
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1])
                {
                    a[i][j] = max({a[i - 1][j], a[i + 1][j], a[i][j - 1], a[i][j + 1]});
                }
            }
        }

        // Process the first and last rows (excluding the corners)
        for (int j = 1; j < m - 1; j++)
        {
            if (a[0][j] > a[0][j + 1] && a[0][j] > a[0][j - 1] && a[0][j] > a[1][j])
            {
                a[0][j] = max({a[1][j], a[0][j - 1], a[0][j + 1]});
            }
            if (a[n - 1][j] > a[n - 1][j + 1] && a[n - 1][j] > a[n - 1][j - 1] && a[n - 1][j] > a[n - 2][j])
            {
                a[n - 1][j] = max({a[n - 2][j], a[n - 1][j - 1], a[n - 1][j + 1]});
            }
        }

        // Process the first and last columns (excluding the corners)
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i][0] > a[i + 1][0] && a[i][0] > a[i - 1][0] && a[i][0] > a[i][1])
            {
                a[i][0] = max({a[i + 1][0], a[i - 1][0], a[i][1]});
            }
            if (a[i][m - 1] > a[i + 1][m - 1] && a[i][m - 1] > a[i - 1][m - 1] && a[i][m - 1] > a[i][m - 2])
            {
                a[i][m - 1] = max({a[i + 1][m - 1], a[i - 1][m - 1], a[i][m - 2]});
            }
        }
        
        // Process the corners
        if (n > 1 && m > 1)
        {
            if (a[0][0] > a[0][1] && a[0][0] > a[1][0])
            {
                a[0][0] = max(a[0][1], a[1][0]);
            }
            if (a[0][m - 1] > a[0][m - 2] && a[0][m - 1] > a[1][m - 1])
            {
                a[0][m - 1] = max(a[0][m - 2], a[1][m - 1]);
            }
            if (a[n - 1][0] > a[n - 1][1] && a[n - 1][0] > a[n - 2][0])
            {
                a[n - 1][0] = max(a[n - 1][1], a[n - 2][0]);
            }
            if (a[n - 1][m - 1] > a[n - 1][m - 2] && a[n - 1][m - 1] > a[n - 2][m - 1])
            {
                a[n - 1][m - 1] = max(a[n - 1][m - 2], a[n - 2][m - 1]);
            }
        }
        
        // Special case: single row
        if (n == 1 && m > 1)
        {
            if (a[0][0] > a[0][1])
            {
                a[0][0] = a[0][1];
            }
            if (a[0][m - 1] > a[0][m - 2])
            {
                a[0][m - 1] = a[0][m - 2];
            }
        }
        
        // Special case: single column
        if (n > 1 && m == 1)
        {
            if (a[0][0] > a[1][0])
            {
                a[0][0] = a[1][0];
            }
            if (a[n - 1][0] > a[n - 2][0])
            {
                a[n - 1][0] = a[n - 2][0];
            }
        }
        }

        // Print the modified matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}