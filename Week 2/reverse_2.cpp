#include <iostream>
#include <vector>
using namespace std;


vector<int> Reversed(const vector<int>& v) {
	vector<int> c = v;
	int n = c.size();
	for (int i = 0; i < n / 2; ++i) {
		  int tmp = c[i];
		  c[i] = c[n - 1 - i];
		  c[n - 1 - i] = tmp;
	}
	return c;
}

int main() {
	return 0;
}