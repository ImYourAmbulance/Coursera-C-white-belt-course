#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (auto& i : a) {
		cin >> i;
		sum += i;
	}
	int aver_num = sum / a.size();
	vector<int> temprt;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > aver_num) {
			temprt.push_back(i);
		}
	}
	cout << temprt.size() << endl;
	for (auto i : temprt) {
		cout << i << " ";
	}

	return 0;
}