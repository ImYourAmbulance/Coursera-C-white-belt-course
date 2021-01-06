#include <iostream>
#include <set>
#include <map>
using namespace std;



int main() {
	map<set<string>, int> stops_to_numbers;
	int q;
	cin >> q;
	int next_index = 1;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		set<string> tmp;
		for (int j = 0; j < n; ++j) {
			string next_stop;
			cin >> next_stop;
			tmp.insert(next_stop);
		}
		if (stops_to_numbers.count(tmp)) {
			cout << "Already exists for " << stops_to_numbers[tmp] << endl;
		}
		else {
			cout << "New bus " << next_index << endl;
			stops_to_numbers[tmp] = next_index;
			++next_index;
		}
	}
	return 0;
}