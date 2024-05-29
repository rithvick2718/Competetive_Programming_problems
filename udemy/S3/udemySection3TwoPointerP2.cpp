#include <iostream>
#include <vector>
using namespace std;

struct Node {
	Node * next;
	int id;
	Node(int val, Node * nxt = NULL) {
		next = nxt;
		id = val;
	}
};

Node * createLinkedList(vector<int> & nums) {
	if (nums.empty())
		return NULL;
	Node * head = new Node(nums[0]);
	Node * tail = head;
	for (size_t i = 1; i < nums.size(); i++) {
		tail->next = new Node(nums[i]);
		tail = tail->next;
	}
	tail->next = head;
	return head;
}

bool isCircular(Node * head) {
	Node * fastPointer = head->next;
	Node * slowPointer = head;
	while(fastPointer != NULL && slowPointer != NULL) {
		if (slowPointer->id == fastPointer->id)
			return true;
		slowPointer = slowPointer->next;
		if (fastPointer->next == NULL)
			break;
		fastPointer = fastPointer->next->next;
	}
	return false;
}

int main() {
	vector<int> nums = {4, 3, 5};
	Node * ls = createLinkedList(nums);
	if (isCircular(ls))
		cout << "circular";
	else
		cout << "not circular";
	return 0;
}
