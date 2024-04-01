#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

struct race {
    int pos1, pos2;
    string startTime; // HH:MM
    double multiplierHorse1, multiplierDraw, multiplierHorse2;
    race(int p1, int p2, string h, double g1, double e, double g2) {
        pos1 = p1;
        pos2 = p2;
        startTime = h;
        multiplierHorse1 = g1;
        multiplierDraw = e;
        multiplierHorse2 = g2;
    }
};

bool compareRaces(race & race1, race & race2) {
	return race1.startTime <= race2.startTime;
}

void sortRaces(vector<race> & races) {
	sort(races.begin(), races.end(), compareRaces);
}

void inputTable(map<string, int> & horseToPosition) {
	string horseName;
	for (int i = 0; i < 20; i++) {
	    cin >> horseName;
	    horseToPosition[horseName] = i;
	}
}

void inputRaces(vector<race> & races, map<string, int> & horseToPosition) {
	string horse1, horse2, startTime;
	double mult1, mult2, mult3;
	for (int i = 0; i < 10; i++) {
	    cin >> horse1 >> horse2 >> startTime;
	    cin >> mult1 >> mult2 >> mult3;
	    races[i] = race(horseToPosition[horse1], horseToPosition[horse2], startTime, mult1, mult2, mult3);
	}
}

double multiplier(race & P) {
    if (abs(P.pos1 - P.pos2) <= 4)
        return P.multiplierDraw;
    else if(P.pos1 > P.pos2)
        return P.multiplierHorse2;
    else
        return P.multiplierHorse1;
}

string takeAway1h30(string startTime) {
    int hourInt = stoi(startTime.substr(0,2)), minutesInt = stoi(startTime.substr(3, 5));
    if (minutesInt >= 30) {
        minutesInt -= 30;
        hourInt--;
    } else {
        minutesInt += 30;
        hourInt -= 2;
    }
    string h = to_string(hourInt), m = to_string(minutesInt);
    if ((int) h.size() == 1)
        h = "0" + h;
    if ((int) m.size() == 1)
        m = "0" + m;
    return h + ":" + m;
}

double findBestStrategy(vector<race> &races) {
	vector<double> DP(10);
	double mult;
	for (int i = 0; i < 10; i++) {
		DP[i] = mult = multiplier(races[i]);
		string maxstartTime = takeAway1h30(races[i].startTime);
		for (int j = 0; j < i; j++) {
			if (races[j].startTime > maxstartTime)
				break;
			if (mult * DP[j] > DP[i])
				DP[i] = mult * DP[j];
		}
		if (i && DP[i - 1] > DP[i]) {
			DP[i] = DP[i - 1];
		}
	}
	return DP[9];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// input league table
    map<string, int> horseToPosition; // 0-indexed
    inputTable(horseToPosition);
    // input races data
    vector<race> races(10, race(0, 0, "00:00", 1, 1, 1));
    inputRaces(races, horseToPosition);
    // sort the races in order of start time
    sortRaces(races);
    // calculate and output the result
    cout << fixed << setprecision(1) << findBestStrategy(races) << '\n';
    return 0;
}