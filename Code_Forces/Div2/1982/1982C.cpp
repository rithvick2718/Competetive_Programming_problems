#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int num, l, r;
        cin >> num >> l >> r;

        vector<long> elements(num); // Instantiate elements with num
        for (long &element : elements) {
            cin >> element;
        }

        int count = 0;
        long current_sum = 0;
        int start_index = 0;

        for (int i = 0; i < num; ++i) {
            if (elements[i] > r) {
                current_sum = 0;
                start_index = i + 1;
                continue;
            }

            current_sum += elements[i];

            while (current_sum < l && i < num - 1) {
                ++i;
                current_sum += elements[i];
            }

            if (current_sum >= l && current_sum <= r) {
                ++count;
                current_sum = 0;
                start_index = i + 1;
            } else if (current_sum > r) {
                current_sum = 0;
                i = start_index;
                ++start_index;
            }
        }

        cout << count << endl;
    }

    return 0;
}