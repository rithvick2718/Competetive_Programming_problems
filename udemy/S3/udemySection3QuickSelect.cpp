#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;

int partition(int pivot, int l, int r) {
	// move pivot to the front
	swap(nums[pivot], nums[l]);
	// at all points, numbers in positions (l, i] will be < nums[pivot]
	int i = l;
	for (int j = l+1; j <= r; j++) {
		if (nums[j] < nums[l]) {
			i++;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[l], nums[i]);
	return i;
}

int selectPivot(int l, int r) {
	// generates random number in [l, r]
	return l + rand() % (r-l);
}

int quickSelect(int l, int r, int order) {
	// order: 0-indexed
	if (l >= r)
		return nums[l];
	int pivot = selectPivot(l, r);
	int k = partition(pivot, l, r);
	if (k == order)
		return nums[k];
	else if (order < k)
		return quickSelect(l, k-1, order);
	return quickSelect(k+1, r, order);
}

int main() {
	nums = {-1, 5, 4, 2, 3, 4, 55, 2, 4, 33, 6, 4, 3, 7, 8, 9, 90};

	for (size_t i = 0; i < nums.size(); i++) {
		cout << quickSelect(0, (int) nums.size()-1, i) << ' ';
		nums = {-1, 5, 4, 2, 3, 4, 55, 2, 4, 33, 6, 4, 3, 7, 8, 9, 90};
	}
	cout << '\n';

	sort(nums.begin(), nums.end());
	for (size_t i = 0; i < nums.size(); i++)
		cout << nums[i] << ' ';
	return 0;
} //well begining after a month now