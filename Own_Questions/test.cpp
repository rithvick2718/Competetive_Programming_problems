    #include <bits/stdc++.h>
    using namespace std;
     
    vector<unsigned int> arr;
     
    inline int countBits(unsigned int num) {
        return num == 0 ? 1 : 32 - __builtin_clz(num);
    }
     
    inline bool getKthBit(unsigned int k, unsigned int num) {
        return (num >> (k - 1)) & 1;
    }
     
    int maxConsecutiveZeros(int bitPos) {
        int maxZeros = 0;
        int currentZeros = 0;
     
        for (unsigned int num : arr) {
            if (getKthBit(bitPos, num)) {
                if (currentZeros > maxZeros) {
                    maxZeros = currentZeros;
                }
                currentZeros = 0;
            } else {
                currentZeros++;
            }
        }
     
        if (currentZeros > maxZeros) {
            maxZeros = currentZeros;
        }
        return maxZeros;
    }
     
    int findLonelyBit(int maxBits) {
        int maxZeros = 0;
     
        for (int i = 1; i <= maxBits; ++i) {
            int zeros = maxConsecutiveZeros(i);
            if (zeros != static_cast<int>(arr.size())) {
                if (zeros > maxZeros) {
                    maxZeros = zeros;
                }
            }
        }
     
        return maxZeros + 1;
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
            arr.resize(n);
     
            for (int i = 0; i < n; ++i) {
                cin >> arr[i];
                if (arr[i] > maxNum) {
                    maxNum = arr[i];
                }
            }
     
            int maxBits = countBits(maxNum);
            cout << findLonelyBit(maxBits) << "\n";
        }
     
        return 0;
    }