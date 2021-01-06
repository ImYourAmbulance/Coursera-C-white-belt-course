#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& item : v) {
		int x;
		cin >> x;
		item = x;
	}
	sort(begin(v), end(v), [](int i,int j) { return (abs(i) < abs(j)); });
	for (const auto& item : v) {
		cout << item << " ";
	}
	cout << endl;
	return 0;
}