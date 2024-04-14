// In my implementation, whenever nums[mid] == key, we discard the upper half. Thus, we always find the first occurrence of key.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> nums = {1, 1, 2, 3, 3, 3, 5, 5, 6, 6, 7,7, 7};
	for (int i = 0; i < (int) nums.size(); i++) {
		int key = nums[i];
		int low = 0, high = (int) nums.size();
	while(low < high) {
		int mid = low + (high - low)/2; // equivalent to (low+high)/2;
		if (nums[mid] < key)
			low = mid+1;
		else
			high = mid;
	}
	if (low < (int) nums.size() && nums[low] == key)
			cout << "Found at position " << low << '\n';
		else
			cout << "Not found. " << key << " would go in position " << low << '\n';
	}

	return 0;
}
