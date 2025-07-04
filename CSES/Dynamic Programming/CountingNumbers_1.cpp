#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Extract digits of x in reverse order (least significant first)
vector<int> getDigits(ll x) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    return digits;
}

// Fast exponentiation: computes base^exp
ll power(ll base, int exp) {
    ll result = 1;
    ll curr = base;
    int e = exp;
    while (e > 0) {
        if (e & 1) result *= curr;
        curr *= curr;
        e >>= 1;
    }
    return result;
}

// Count how many digits d satisfy low < d < high and d != exclude
int countBetween(int low, int high, int exclude) {
    int cnt = 0;
    for (int d = 0; d < 10; ++d) {
        if (low < d && d < high && d != exclude) {
            ++cnt;
        }
    }
    return cnt;
}

// Check that no two consecutive non-leading-zero digits are equal
bool isValid(const vector<int>& digits) {
    int n = digits.size();
    if (n <= 1) return true;
    int i = 0;
    // skip leading zeros
    while (i < n && digits[i] == 0) ++i;
    for (; i + 1 < n; ++i) {
        if (digits[i] == digits[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ll start, end;
    cin >> start >> end;

    // Get digit vectors (least significant first)
    vector<int> dStart = getDigits(start);
    vector<int> dEnd   = getDigits(end);

    // Pad the shorter vector with zeros
    while (dStart.size() < dEnd.size()) {
        dStart.push_back(0);
    }
    // Reverse to make most significant digit first
    reverse(dStart.begin(), dStart.end());
    reverse(dEnd.begin(),   dEnd.end());

    int n = dEnd.size();
    ll result = 0;

    if (n == 0) {
        // both start and end are zero
        cout << 1 << "\n";
        return 0;
    }

    // Find first index where digits differ
    int firstDiff = 0;
    while (firstDiff < n && dStart[firstDiff] == dEnd[firstDiff]) {
        ++firstDiff;
    }

    // Check that the common prefix has no equal consecutive digits
    bool prefixOK = (firstDiff != n);
    for (int i = 0; i + 1 < firstDiff; ++i) {
        if (dEnd[i] == dEnd[i+1]) {
            prefixOK = false;
            break;
        }
    }

    if (prefixOK) {
        // Phase 1: count choices at the first differing digit
        int betweenCount = 0;
        if (firstDiff > 0) {
            betweenCount = countBetween(
                dStart[firstDiff],
                dEnd[firstDiff],
                dEnd[firstDiff - 1]
            );
        } else {
            betweenCount = countBetween(
                dStart[firstDiff],
                dEnd[firstDiff],
                -1
            );
        }
        result += (ll)betweenCount * power(9, n - firstDiff - 1);

        // Phase 2: extend the upper bound prefix
        bool canExtendHigh = (firstDiff == 0)
            || (dEnd[firstDiff - 1] != dEnd[firstDiff]);
        if (canExtendHigh) {
            for (int pos = firstDiff + 1; pos < n; ++pos) {
                // break if last two digits would be equal
                if (pos >= 2 && dEnd[pos-1] == dEnd[pos-2]) {
                    break;
                }
                int choices = countBetween(
                    -1,
                    dEnd[pos],
                    dEnd[pos-1]
                );
                result += (ll)choices * power(9, n - pos - 1);
            }
        }

        // Phase 3: extend the lower bound prefix
        bool canExtendLow = (firstDiff == 0)
            || (dStart[firstDiff - 1] != dStart[firstDiff]);
        if (canExtendLow) {
            // find first non-zero digit in start
            int firstNonZero = 0;
            while (firstNonZero < n && dStart[firstNonZero] == 0) {
                ++firstNonZero;
            }

            if (firstNonZero <= firstDiff) {
                // no all-zero prefix to skip
                for (int pos = firstDiff + 1; pos < n; ++pos) {
                    if (pos >= 2 && dStart[pos-2] == dStart[pos-1]) {
                        break;
                    }
                    int choices = countBetween(
                        dStart[pos],
                        10,
                        dStart[pos-1]
                    );
                    result += (ll)choices * power(9, n - pos - 1);
                }
            } else {
                // skip the all-zero positions up to firstNonZero
                ++firstDiff;
                while (firstDiff < firstNonZero) {
                    result += power(9, n - firstDiff);
                    ++firstDiff;
                }
                // account for the position firstDiff itself
                if (firstDiff < n) {
                    result += (ll)countBetween(
                        dStart[firstDiff],
                        10,
                        -1
                    ) * power(9, n - firstDiff - 1);
                }
                // then extend as usual
                for (int pos = firstDiff + 1; pos < n; ++pos) {
                    if (pos >= 2 && dStart[pos-1] == dStart[pos-2]) {
                        break;
                    }
                    int choices = countBetween(
                        dStart[pos],
                        10,
                        dStart[pos-1]
                    );
                    result += (ll)choices * power(9, n - pos - 1);
                }
            }
        }
    }

    // Include the endpoints if they form valid sequences
    if (start == end) {
        if (isValid(dStart)) {
            ++result;
        }
    } else {
        if (isValid(dStart)) {
            ++result;
        }
        if (isValid(dEnd)) {
            ++result;
        }
    }

    cout << result << "\n";
    return 0;
}