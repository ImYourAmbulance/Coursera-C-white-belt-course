#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Spaces(string s) {
	int k = 0;
	for (auto a : s) {
		if (a == ' ') {
			++k;
		}
	}
	return k;
}
void Add(vector<string>& current_month, int day, string affair) {
	current_month[day] += affair + " ";
	while (current_month[day][current_month[day].size() - 1] == ' ') {
		current_month[day].resize(current_month[day].size() - 1);
	}
	current_month[day] += " ";
}


void Dump(const vector<string>& current_month, int day) {
	if (day <= current_month.size() - 1) {
	  cout << Spaces(current_month[day]) << " ";
	  cout << current_month[day].substr(0, current_month[day].size() - 1) << endl;
	}
	else {
		cout << 0 << endl;
	}
}


void Next(const vector<int>& months, vector<string>& current_month, int next_month) {
	// Putting off affairs
	while (current_month.size() - 1 > months[next_month]) {
		Add(current_month, current_month.size() - 2,
		current_month[current_month.size() - 1]);
		current_month.pop_back();
	}
}


int main() {
	vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<string> current_month(32);
	int q;
	int current_month_index = 0;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;
		if (operation_code == "NEXT") {
			++current_month_index;
			current_month_index = current_month_index % 12;
			Next(months, current_month, current_month_index);
		}
		else if (operation_code == "DUMP") {
			int day;
			cin >> day;
			Dump(current_month, day);
		}
		else {
			int day;
			cin >> day;
			string affair;
			cin >> affair;
			Add(current_month, day, affair);
		}
	}
	return 0;
}
