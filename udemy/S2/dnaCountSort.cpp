#include <fstream>
#include <map>
#include <vector>
using namespace std;

void sortDNA(string & dna) {
	// O(N)
	// count occurrences of each chemical: O(N)
	map<char, int> occ;
	for (char c: dna)
		occ[c]++;
	// rewrite the string in sorted order: O(N)
	vector<char> chemicals = {'A', 'C', 'G', 'T'};
	string ret = ""; // ret = occ['A'] * 'A' + occ['C'] * 'C' + occ['G'] * 'G' + occ['T'] * 'T';
	for (char chem: chemicals) {
		for (int i = 0; i < occ[chem]; i++)
			ret.push_back(chem);
	}
	dna = ret;
}

int main() {
	ifstream cin;
	cin.open("dna.txt");
	string dna;
	cin >> dna;
	cin.close();
	sortDNA(dna);
	ofstream cout;
	cout.open("sorteddna.txt");
	cout << dna << '\n';
	cout.close();
	return 0;
}
