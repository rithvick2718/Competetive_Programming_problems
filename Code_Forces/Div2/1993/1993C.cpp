#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int max_time = *max_element(a.begin(), a.end());
        int limit = max_time + 2 * k * n; // set a reasonable limit

        bool found = false;
        for (int time = max_time; time <= limit; ++time) {
            bool all_on = true;

            for (int i = 0; i < n; ++i) {
                int diff = time - a[i];
                if (diff < 0 || (diff / k) % 2 == 1) {
                    all_on = false;
                    break;
                }
            }

            if (all_on) {
                cout << time << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}
