#include <bits/stdc++.h>
using namespace std;

vector<unsigned int> arr;

int countBits(unsigned int num) {
    int bits = 0;
    while (num != 0) {
        num >>= 1;
        bits++;
    }
    return bits;
}

bool getKthBit(unsigned int k, unsigned int num) {
    return ((bool)((num >> (k - 1)) & 1));
}

int maxConsecutiveZeros(int bitPos) {
    int maxZeros = 0;
    int currentZeros = 0;

    for (unsigned int num : arr) {
        if (getKthBit(bitPos, num)) {
            maxZeros = max(maxZeros, currentZeros);
            currentZeros = 0;
        } else {
            currentZeros++;
        }
    }

    maxZeros = max(maxZeros, currentZeros);
    return maxZeros;
}

int findLonelyBit(int maxBits) {
    int maxZeros = 0;

    for (int i = 1; i <= maxBits; ++i) {
        int zeros = maxConsecutiveZeros(i);
        if (zeros != static_cast<int>(arr.size())) {
            maxZeros = max(maxZeros, zeros);
        }
    }

    return (maxZeros + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        arr.clear();

        int n;
        cin >> n;
        unsigned int maxNum = 0;
        for (int i = 0; i < n; ++i) {
            unsigned int h;
            cin >> h;
            maxNum = max(maxNum, h);
            arr.push_back(h);
        }

        int maxBits = countBits(maxNum);
        cout << findLonelyBit(maxBits) << "\n";
    }

    return 0;
}