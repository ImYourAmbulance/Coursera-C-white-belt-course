#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
	const string path = "input.txt";
	ifstream input(path);
	double n;
	double m;
	input >> n;
	input.ignore(1);
	input >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			double current_digit;
			input >> current_digit;
			cout << setw(10);
			cout << current_digit;
			if (j < m - 1) {
				cout << ' ';
				input.ignore(1);
			}
		}
		if (i != m - 1) {
			cout << endl;
		}
	}
	return 0;
}