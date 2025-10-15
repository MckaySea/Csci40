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

int main ()
{
	//This is equivalent to string filename; cout << "Please enter a filename\n"; cin >> filename;
	//But on one line instead of three, because I'm cool like that
	string filename = read("Please enter a filename:\n");
	//Next...
	//Do you remember how to open a file?
	//How to check to see if the file opened successfully?
	//How do you store data in a vector?
	//How do you average values across a vector?
}
