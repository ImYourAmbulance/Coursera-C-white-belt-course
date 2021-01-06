#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Print(const vector<vector<string>>& current_month) {
	for (int i = 0; i < current_month.size(); ++i) {
		cout << i + 1 << " ";
		for (string element: current_month[i]) {
			cout << " " << element;
		}
		cout << endl;
	}
}

void Add(vector<vector<string>>& current_month, int day, string concern) {
	//cout << "Before Add" << endl;
	//Print(current_month);
	current_month[day - 1].push_back(concern);
	//cout << "After Add" << endl;
	//Print(current_month);
}

void Dump(const vector<vector<string>>& current_month, int day) {
	if (day > current_month.size()) {
			cout << 0 << endl;
	}
	else {
		cout << current_month[day - 1].size() ;
		for (string element : current_month[day - 1])  {
			cout << " " << element;
		}
		cout << endl;
	}
}
/*
void Next(vector<vector<string>>& current_month, const vector<int>& months, const int& next_month) {
	while (current_month.size() > months[next_month]) {
		for (string element : current_month[current_month.size() - 1]) {
			Add(current_month, current_month.size() - 1, element);
		}
		current_month.pop_back();
	}
	if (current_month.size() < months[next_month]) {
		int n = months[next_month];
		current_month.resize(n);

	}
}*/
void Next(vector<vector<string>>& current_month, const vector<int>& months, const int& next_month) {
	if (months[next_month] < current_month.size()) {
		vector<string>& last_day_concerns = current_month[months[next_month] - 1];
		for (int day = months[next_month]; day < current_month.size(); ++ day) {
			last_day_concerns.insert(
					end(last_day_concerns),
					begin(current_month[day]), end(current_month[day]));
		}
	}
	current_month.resize(months[next_month]);
}

int main() {
	vector<vector<string>> current_month(31);
	vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int next_month = 1;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		string command;
		cin >> command;
		if (command == "NEXT") {
				Next(current_month, months, next_month);
				++next_month;
				next_month %= 12;
		}
		else {
			int day;
			cin >> day;
			if (command == "DUMP") {
				Dump(current_month, day);
			}
			else if (command == "ADD")  {
				string concern;
				cin >> concern;
				Add(current_month, day, concern);
			}
		}
	}
	return 0;
}