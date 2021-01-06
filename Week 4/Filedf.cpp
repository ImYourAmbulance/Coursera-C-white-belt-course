#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
//D:\\Desktop
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
			int x;
			input >> x;
			cout << setw(10);
			cout << x;
			input.ignore(1);
			if (j != m - 1) {
				cout << ' ';
			}
		}
		if (i != n - 1) {
			cout << endl;
		}
	}
	return 0;
}