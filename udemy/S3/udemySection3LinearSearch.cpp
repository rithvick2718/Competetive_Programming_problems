#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> nums = {1, 4, 2, 3, 7, 1, 5, 6};
	int i = 0;
	int key = -1;
	for (; i < (int) nums.size(); i++) {
		if (nums[i] == key)
			break;
	}
	if (i == (int) nums.size())
		cout << "Not found\n";
	else
		cout << "Found at position " << i << '\n';
	return 0;
}
