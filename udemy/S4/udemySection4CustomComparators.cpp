#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

bool cmp(int a, int b) {
	// returns whether a < b
	if (a % 3 == 0) {
		if (b % 3 == 0)
			return a < b;
		return true;
	} else if (b % 3 == 0)
		return false;
	else
		return a < b;
}

int main() {
	vector<int> nums = {3, 4, 2, 1, 3, 4, 5, 7, 8, 9, 93, 90, 87, 68};
	for (int n: nums)
		cout << n << ' ';
	cout << '\n';



	// Create set, map and PQ
	set<int, decltype(&cmp)> numsSet(cmp);
	map<int, int, decltype(&cmp)> numsMap(cmp); // (number, count)
	priority_queue<int, vector<int>, decltype(&cmp)> numsQueue(cmp);

	for (int n: nums) {
		numsSet.insert(n);
		numsMap[n]++;
		numsQueue.push(n);
	}



	// print out the set
	cout << "Set contents:\n";
	for (int n: numsSet)
		cout << n << '\n';
	cout << '\n';


	// print out the map
	cout << "Map contents:\n";
	for (auto it: numsMap)
		cout << '(' << it.first << ", " << it.second << ")\n";
	cout << '\n';


	// print out the priority queue
	cout << "PQ contents:\n";
	while(!numsQueue.empty()) {
		int n = numsQueue.top();
		numsQueue.pop();
		cout << n << '\n';
	}
	return 0;
}
