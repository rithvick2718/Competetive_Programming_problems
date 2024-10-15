#include <iostream>
#include <vector>
using namespace std;

long long int p = 127; // prime approximately equal to the size of the alphabet used
long long int m = 1e9 + 9; // cardinality

// Let SLen = S.length():
// returns (S[0]*p^(SLen-1) + S[1]*p^(SLen-2) + ... + S[SLen-1]*p^0) % m
long long int stringHash(string S) {
	// (a+b) % m = a%m + b%m
	// (a*c) % m = (a%m) * (c%m)
	long long int hashValue = 0;
	for (size_t i = 0; i < S.length(); i++)
		hashValue = (p*hashValue + S[i]) % m;
	return hashValue;
}

// checks if key == S[pos..pos+key.length())
bool equalPos(string & S, string & key, int pos) {
	for (int i = pos; i < pos + (int) key.length(); i++) {
		if (S[i] != key[i-pos])
			return false;
	}
	return true;
}

// takes stringHash(S[i, i+keyLen)) and returns stringHash(S(i, i+keyLen])
long long int reHash(long long int curHash, string & S, int i,
		long long int powerLength, int keyLen) {
	curHash = (p*(curHash - S[i]*powerLength) + S[i + keyLen]) % m;
	if (curHash < 0)
		curHash += m;
	return curHash;
}

// returns a vector containing the starting positions of key in S
vector<int> searchString(string & S, string & key) {
	if (S.length() < key.length())
		return {};

	vector<int> occ = {};
	int keyLen = (int) key.length(), SLen = (int) S.length();

	long long int keyHash = stringHash(key);
	long long int curHash = stringHash(S.substr(0, keyLen)); // [0, keyLen)

	// powerLength = p^(keyLen-1) % m
	long long int powerLength = 1;
	for (int i = 0; i < keyLen-1; i++)
		powerLength = (powerLength * p) % m;

	for (int i = 0; i <= SLen - keyLen; i++) {
		// curHash = stringHash(S[i, i+keyLen))
		if (keyHash == curHash && equalPos(S, key, i))
			occ.push_back(i);
		if (i < SLen - keyLen)
			curHash = reHash(curHash, S, i, powerLength, keyLen);
	}
	return occ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string A, B;
	int T;
	cin >> T;
	while(T--) {
		cin >> A >> B;
		vector<int> pos = searchString(A, B);
		if (pos.size()) {
			cout << pos.size() << '\n';
			cout << pos[0]+1;
			for (size_t i = 1; i < pos.size(); i++)
				cout << " " << pos[i]+1;
			cout << '\n';
		} else cout << "Not Found\n";
		if (T > 0)
			cout << '\n';
	}
	return 0;
}
