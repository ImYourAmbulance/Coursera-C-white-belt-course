#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Calculate_Words(string s) {
	int number_of_words = 0;
	if (s != "") {
	  for (auto element : s) {
		  if (element == ' ') {
		    ++number_of_words;
		  }
	  }
	  ++number_of_words;
	}
	return number_of_words;
}


void Add(vector<string>& current_month, int day, string concern) {
	if (current_month[day] != "") {
	  current_month[day] += " ";
	}
	current_month[day] += concern;
}


void Dump(const vector<string>& current_month, int day) {
	int days_in_month = current_month.size() - 1;
	if (day > days_in_month) {
		cout << 0 << endl;
	}
	else {
		cout << Calculate_Words(current_month[day]) << " " << current_month[day] << endl;
	}
}


/*
void Next(vector<string>& current_month, const vector<int>& months, int next_month) {
	int days_in_current_month = current_month.size() - 1;
	int days_in_next_month = months[next_month];
	if (days_in_next_month < days_in_current_month) {
		// We put concern from the last day on second-to-last day
		// After this we delete last day
		// After this we repeate proccess
		// until we've got days in next month = days in current month
		while (days_in_next_month < days_in_current_month) {
			int last_index = current_month.size() - 1;
			Add(current_month, last_index - 1, current_month[last_index]);
			current_month.pop_back();
		}
	}
	else if (days_in_next_month > days_in_current_month) {
		current_month.resize(days_in_next_month + 1);
	}
}
*/


void Next(vector<string>& current_month, const vector<int>& months, int next_month) {
	if (months[next_month] < current_month.size() - 1) {
		// We put concern from the last day on second-to-last day
		// After this we delete last day
		// After this we repeate proccess
		// until we've got days in next month = days in current month
		while (months[next_month] < current_month.size() - 1) {
			int last_index = current_month.size() - 1;
			Add(current_month, current_month.size() - 2, current_month[current_month.size() - 1]);
			current_month.pop_back();
		}
	}
	else if (months[next_month] > current_month.size() - 1) {
		current_month.resize(months[next_month] + 1);
	}
}


int main() {
	vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<string> current_month(32);
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
			else {
				string concern;
				cin >> concern;
				Add(current_month, day, concern);
			}
		}
	}

	return 0;
}