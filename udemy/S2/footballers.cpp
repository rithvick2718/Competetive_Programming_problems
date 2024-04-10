#include <fstream>
#include <vector>
using namespace std;

struct player {
	double height;
	bool football;
	player(double h, bool f) {
		height = h;
		football = f;
	}
};

void inputFootballers(vector<player> & players) {
	ifstream fin;
	fin.open("footballData.txt");
	double height;
	bool football;
	for (int i = 0; i < 10000; i++) {
		fin >> height >> football;
		players.push_back(player(height, football));
	}
	fin.close();
}

void outputFootballers(vector<vector<int>> & football, vector<vector<int>> & nonFootball, vector<player> & players) {
	ofstream fout;
	fout.open("sortedFootball.txt");
	for (int i = 0; i < 5; i++) {
		for (int index: football[i])
			fout << players[index].height << " 1\n";
		for (int index: nonFootball[i])
			fout << players[index].height << " 0\n";
	}
	fout.close();
}

void sortFootballers(vector<player> & players) {
	// O(N)
	// Arrange into buckets: O(N)
	vector<vector<int>> buckets(5);
	for (int i = 0; i < 10000; i++) {
		if(players[i].height <= 1.20)
			buckets[0].push_back(i);
		else if (players[i].height <= 1.40)
			buckets[1].push_back(i);
		else if (players[i].height <= 1.60)
			buckets[2].push_back(i);
		else if (players[i].height <= 1.80)
			buckets[3].push_back(i);
		else
			buckets[4].push_back(i);
	}
	// Sort buckets: O(N) in total
	vector<vector<int>> football(5), nonFootball(5);
	for (int i = 0; i < 5; i++) {
		for (size_t j = 0; j < buckets[i].size(); j++) {
			if (players[buckets[i][j]].football)
				football[i].push_back(buckets[i][j]);
			else
				nonFootball[i].push_back(buckets[i][j]);
		}
	}
	// Output the sorted list
	outputFootballers(football, nonFootball, players);
}

int main() {
	vector<player> players;
	inputFootballers(players);
	sortFootballers(players);
	return 0;
}
