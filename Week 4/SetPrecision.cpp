#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
	const string path = "input.txt";
	ifstream input(path);
	cout << fixed << setprecision(3);
	for(double x; input >> x;) {
		cout << x << endl;
	}
	return 0;
}