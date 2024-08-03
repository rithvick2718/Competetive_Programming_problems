#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, int> dict;

bool valid(vector<int> & brackets) {
	/*
	'{' <=> 1
	'}' <=> 2
	'(' <=> 3
	')' <=> 4
	'[' <=> 5
	']' <=> 6
	 */
	stack<int> st;
	int N = (int) brackets.size();
	for (int i = 0; i < N; i++) {
		if (st.empty()) {
			if (brackets[i] % 2 == 1) // opening bracket -> add to stack
				st.push(brackets[i]);
			else // closing bracket with empty stack -> WRONG
				return false;
		}
		else if (st.top() == brackets[i] - 1 && brackets[i] % 2 == 0)
			st.pop(); // the last opening bracket matches the current bracket, which closes it
		else if (brackets[i] % 2 == 1)
			st.push(brackets[i]); // opening bracket -> add to stack
		else return false;
	}
	return st.empty(); // if st is not empty, there are unclosed opening brackets
}

vector<int> transform(string S) {
	vector<int> brackets;
	for (char c: S) {
		if (dict.find(c) == dict.end())
			continue;
		brackets.push_back(dict[c]);
	}
	return brackets;
}

int main() {
	dict['{'] = 1;
	dict['}'] = 2;
	dict['('] = 3;
	dict[')'] = 4;
	dict['['] = 5;
	dict[']'] = 6;
	int T;
	string line;
	getline(cin, line);
	T = stoi(line);
	while(T--) {
		getline(cin, line);
		vector<int> brackets = transform(line);
		if (valid(brackets)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
