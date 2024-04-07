#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> primes;
bool isPrime(int n) {
if (n <= 1) return false;
 for (int i = 2; i*i <= n; i++) {
 if (n % i == 0) return false;
 }
 return true;
 }

 bool canMake(int x) {
 for (size_t i = 0; i < primes.size(); i++) {
 for (size_t j = i; j < primes.size(); j++) {
 for (size_t k = j; k < primes.size(); k++) {
 if (primes[i] + primes[j] + primes[k] == x)
 return true;
 }
 }
 }
 return false;
 }

 int main() {
 ios::sync_with_stdio(false);
 cin.tie(NULL);
 primes = vector<int>();
 for (int i = 2; i <= 255; i++)
 if (isPrime(i)) primes.push_back(i);
 int h, w, x;
 cin >> h >> w;
 for (int i = 0; i < h; i++) {
 for (int j = 0; j < w; j++) {
 cin >> x;
 if (canMake(x))
 cout << "POSSIBLE\n";
 else
 cout << "IMPOSSIBLE\n";
 }
 }
 return 0;
 }