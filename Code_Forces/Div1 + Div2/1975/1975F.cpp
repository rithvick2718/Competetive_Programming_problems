#include <bits/stdc++.h>
using namespace std;

int countbits(int num) // Brian Kernighan's algorithm
{
    int count = 0;
    while (num)
    {
        num = num & (num - 1);
        count++;
    }
    return count;
}

int SUT(int s, int t)
{
    return countbits(s & t);
}

bool checker(int s, int t, int v)
{
    return ((v >> SUT(s, t)) & 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    const int m = (1 << n) - 1;
    
    // Use vector<bool> for dynamic size and initialization
    vector<bool> S(m, true);
    
    int v;
    int wrong = 0;
    
    for (int i = 0; i < m; i++) // i is for v values t = i+1
    {
        cin >> v;
        
        // Use a temporary vector to avoid modifying S during iteration
        vector<bool> newS = S;
        
        for (int j = 0; j < m; j++) // j is for array S
        {
            if (S[j])
            {
                if (!checker(j + 1, i + 1, v))
                {
                    newS[j] = false;
                    wrong++;
                }
            }
        }
        
        // Update S only after the entire inner loop is done
        S = newS;
    }
    
    cout << m - wrong << "\n";
    for (int i = 0; i < m; i++)
    {
        if (S[i])
        {
            cout << i + 1 << "\n";
        }
    }
    
    return 0;
}