#include <iostream>
#include <vector>
#include <string>
using namespace std;


void MoveStrings(vector<string>& a, vector<string>& b) {
	for (auto i : a) {
		b.push_back(i);
	}
	a.clear();
}


int main() {
	return 0;
}