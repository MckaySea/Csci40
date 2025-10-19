#include "/public/read.h"
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

void die() {
	cout << "You dun goofed.\n";
	exit(0);
}

int main() {
	//This is equivalent to string filename; cout << "Please enter a filename\n"; cin >> filename;
	//But on one line instead of three, because I'm cool like that
	string filename = read("Please enter a filename:\n");
//Next...
//Do you remember how to open a file?
	ifstream inputFile(filename);
	//How to check to see if the file opened successfully?
	if (!inputFile.is_open()) {
		die();
	}
	int N;
	if (!(inputFile >> N)) {
		die();
	}
	if (N < 2) {
		die();
	}
	//initializing our breifcase vector here
	vector<int> briefCases(N);
	// vector to determine which cases have already been opened, using the same amount of elemtns as briefcase, we'll make elements true in the same position as briefcases dollar amounts thare
	//are selected, and default all elements to false initially
	vector<bool> isOpened(N, false);
	//self explanatory, setting casesremaining to the initial amount of N
	int casesRemaining = N;

	//im reading N amount of dollar amounts into the briefCases vector here
	for (int i = 0; i < N; i++) {
		if (!(inputFile >> briefCases[i])) {
			die();
		}

		if (briefCases[i] <= 0) {
			die();
		}
	}
	//just testing to make sure we can open and see the file and it being read into briefcases vectr
	

	// Initialize Variables
	int totalCaseValue = 0;
	int totalOpenValue = 0;
	int totalRemainValue = 0;
	int averageRemain = 0;

	// Calculates the combined value of every briefcase.
	for (int i = 0; i < briefCases.size(); i++) {
		totalCaseValue += briefCases[i];
	}

	while (casesRemaining > 1) {
		int openedCase;

		cout << "Please enter a briefcase to open:\n";
		if (!(cin >> openedCase)) {
			die();
		}

		if (openedCase == -1) {
			cout << "You won " << averageRemain << " dollars!\n"; // Outputs players winnings if they decide to take the deal.
			break;
		}

		if (openedCase < 0 || openedCase >= N) {
			die();
		}

		if (isOpened[openedCase]) {
			die();
		}

		cout << "That briefcase held " << briefCases[openedCase] << " dollars" << endl;

		isOpened[openedCase] = true;
		casesRemaining--;

		//How do you average values across a vector?

		// Calculates the average value of the remaining briefcases.
		totalOpenValue += briefCases[openedCase];
		totalRemainValue = (totalCaseValue - totalOpenValue);
		averageRemain = (totalRemainValue / casesRemaining);

		// Player receives offers as long as their is more than 1 briefcase remaining.
		if (casesRemaining > 1)
			cout << "I will offer you " << averageRemain << " dollars to walk away." << endl;

		// If only 1 case remains the game ends and the player receives whatever was in the last case.
		if (casesRemaining == 1)
			cout << "You won " << totalRemainValue << " dollars!\n";
	}
}
