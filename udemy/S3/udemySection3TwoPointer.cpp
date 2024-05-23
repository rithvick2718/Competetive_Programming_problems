#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> nums = {1, 2, 3, 3, 3, 4, 5, 7, 9, 10};
	int key = 26;
	int low = 0, high = (int) nums.size()-1;
	while(low < high) {
		int S = nums[low]+nums[high];
		if (S == key)
			break;
		else if (S < key)
			low++;
		else
			high--;
	}
	if (nums[low]+nums[high] == key && low != high)
		cout << key << " is the sum of positions " << low << " and " << high << ".\n";
	else
		cout << key << " cannot be obtained by summing two values in nums.\n";
	return 0;
}
