#include <iostream>
#include <vector>
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
	// generates random number between in [l, r]
	return l + rand() % (r-l);
}

void quickSort(int l, int r) {
	if (l >= r)
		return;
	int pivot = selectPivot(l, r);
	int k = partition(pivot, l, r);
	quickSort(l, k-1);
	quickSort(k+1, r);
}

int main() {
	nums = {-1, 5, 4, 2, 3, 4, 55, 2, 4, 33, 6, 4, 3, 7, 8, 9, 90};
	quickSort(0, (int) nums.size() - 1);
	for (size_t i = 0; i < nums.size(); i++)
		cout << nums[i] << ' ';
	return 0;
}
