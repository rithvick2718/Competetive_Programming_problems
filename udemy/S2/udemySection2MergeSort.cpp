#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;

void merge(int l, int r) {
	int mid = l + (r-l)/2;
	// copy each half into a new vector, as the result will go into the nums vector
	vector<int> left(mid-l+1);
	for (int i = l; i <= mid; i++)
		left[i-l] = nums[i];
	vector<int> right(r-mid);
	for (int i = mid+1; i <= r; i++)
		right[i-mid-1] = nums[i];
	// iterate until one half is exhausted
	size_t leftIt = 0, rightIt = 0;
	while(leftIt < left.size() && rightIt < right.size()) {
		if (left[leftIt] <= right[rightIt]) {
			nums[l + leftIt + rightIt] = left[leftIt];
			leftIt++;
		} else {
			nums[l + leftIt + rightIt] = right[rightIt];
			rightIt++;
		}
	}
	// fill in with any remaining elements
	while(leftIt < left.size()) {
		nums[l + leftIt + rightIt] = left[leftIt];
		leftIt++;
	}
	while(rightIt < right.size()) {
		nums[l + leftIt + rightIt] = right[rightIt];
		rightIt++;
	}
}

void mergeSort(int l, int r) {
	if (l >= r)
		return;
	int mid = l + (r-l)/2; // equivalent to (l+r)/2
	mergeSort(l, mid);
	mergeSort(mid+1, r);
	merge(l, r);
}

int main() {
	nums = {-1, 5, 4, 2, 3, 4, 55, 2, 4, 33, 6, 4, 3, 7, 8, 9, 90};
	mergeSort(0, (int) nums.size()-1);
	for (size_t i = 0; i < nums.size(); i++)
		cout << nums[i] << ' ';
	return 0;
}