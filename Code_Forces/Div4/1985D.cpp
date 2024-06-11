#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> ol;
        vector<int> il;

        // Clear input buffer before reading the grid
        cin.ignore();

        for (int i = 0; i < n; i++) // for each line
        {
            string line;
            getline(cin, line);  // Read the entire line

            for (int j = 0; j < m; j++)
            {
                if (line[j] == '#')
                {
                    ol.push_back(j + 1);
                    il.push_back(i + 1);
                    break;
                }
            }
        }
        auto min_it = min_element(ol.begin(),ol.end());
        int index = distance(ol.begin(),min_it);
        cout<<il[index]<<" "<<ol[0]<<"\n";
    }

    return 0;
}
