#include <iostream>
#include <vector>
using namespace std;


void Reverse(vector<int>& v) {
	vector<int> tmp = v;
	for (int i = 0; i < tmp.size(); ++i) {
		v[i] = tmp[tmp.size() - i - 1];
	}
}


int main() {
	return 0;
}