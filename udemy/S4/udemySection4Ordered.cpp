#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	// Ordered map operations
	map<string, int> studentAges;
	cout << studentAges.empty() << '\n'; // O(1)
	studentAges["Blanca"] = 18; // O(log n)
	studentAges["Antonio"] = 23;
	studentAges["Phillip"] = 19;
	studentAges["Antonio"]++; // O(log n)
	for (auto const & [key, val] : studentAges) // O(n)
	    cout << key << " is " << val << " years old.\n";
	if (studentAges.find("Blanca") != studentAges.end()) // O(log n)
		cout << "Found\n";
	else
		cout << "Not found\n";
	studentAges.erase("Blanca"); // O(log n)
	cout << studentAges.size() << '\n'; // O(1)
	cout << studentAges["Blanca"] << '\n'; // O(log n)

	// Ordered set operations
	set<string> students;
	students.insert("Julia"); // O(log n)
	students.insert("Martha");
	for (auto const & val: students) // O(n)
		cout << val << '\n';
	if (students.find("Blanca") != students.end()) // O(log n)
		cout << "Found\n";
	else
		cout << "Not found\n";
	students.erase("Julia"); // O(log n)
	cout << students.size() << '\n'; // O(1)
	return 0;
}
