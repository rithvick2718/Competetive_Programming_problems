#include <iostream>
using namespace std;

int badHash(int phoneNumber) {
	// return first 3 digits
	return phoneNumber / 1e6;
}

int goodHash(int phoneNumber) {
	// return last 3 digits
	return phoneNumber % 1000;
}

int main() {
	int phone = 618765456;
	cout << badHash(phone) << " " << goodHash(phone);
	return 0;
}
