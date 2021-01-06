#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;



int main() {
	map<string, vector<string>> buses_and_stops;
	vector<string> buses_row;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;
		if (operation_code == "ALL_BUSES") {
			if (buses_and_stops.size()) {
				for (const auto& item : buses_and_stops) {
					cout << "Bus " << item.first << ": ";
					for (const auto& stop : item.second) {
						cout << stop << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "No buses" << endl;
			}
		}
		else if (operation_code == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			if (buses_and_stops.count(bus)) {
				for (const auto& stop : buses_and_stops[bus]) {
					bool is_there_any_bus = false;
					cout << "Stop " << stop << ": ";
						for (const auto& next_bus : buses_row) {
							if (next_bus != bus and count(cbegin((buses_and_stops[next_bus])),
							                      	  cend((buses_and_stops[next_bus])), stop)) {
								is_there_any_bus = true;
								cout << next_bus << " ";
							}
						}
						if (!is_there_any_bus) {
							cout << "no interchange";
						}
						cout << endl;
				}
			}
			else {
				cout << "No bus" << endl;
			}
		}
		else if (operation_code == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			bool is_here_this_stop = false;
			for (const auto& next_bus : buses_row) {
				for (const auto& next_stop : buses_and_stops[next_bus]) {
					if (next_stop == stop) {
						is_here_this_stop = true;
						cout << next_bus << " ";
					}
				}
			}
			if (!is_here_this_stop) {
				cout << "No stop";
			}
			cout << endl;
		}
		else if (operation_code == "NEW_BUS") {
			string bus;
			int stop_count;
			cin >> bus >> stop_count;
			buses_row.push_back(bus);
			for (int i = 0; i < stop_count; ++i) {
				string stop_i;
				cin >> stop_i;
				buses_and_stops[bus].push_back(stop_i);
			}
		}
	}
	return 0;
}