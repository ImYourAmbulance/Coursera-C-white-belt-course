#include <iostream>
#include <vector>
#include <map>
using namespace std;


void ChangeCapital(
					map<string, string>& countries_and_capitals,
					string country, string new_capital) {
	if (!countries_and_capitals.count(country)) {
		countries_and_capitals[country] = new_capital;
		cout << "Introduce new country " << country;
		cout << " with capital " << new_capital;
		cout << endl;
	}
	else if (countries_and_capitals[country] == new_capital) {
		cout << "Country " << country << " hasn't changed its capital";
		cout << endl;
	}
	else if (countries_and_capitals[country] != new_capital) {
		string old_capital = countries_and_capitals[country];
		countries_and_capitals[country] = new_capital;
		cout << "Country " << country << " has changed its capital from ";
		cout << old_capital << " to " << new_capital<< endl;
	}
}

void Rename(
			map<string, string>& countries_and_capitals,
			string old_country_name, string new_country_name) {
	if (!countries_and_capitals.count(old_country_name) ||
			(old_country_name == new_country_name) ||
			countries_and_capitals.count(new_country_name)) {
		cout << "Incorrect rename, skip" << endl;
	}
	else {
		string capital = countries_and_capitals[old_country_name];
		countries_and_capitals.erase(old_country_name);
		countries_and_capitals[new_country_name] = capital;
		cout << "Country " << old_country_name << " with capital ";
		cout << capital <<  " has been renamed to " << new_country_name;
		cout << endl;
	}

}


void About(map<string, string>& countries_and_capitals, string country) {
	if (countries_and_capitals.count(country) != 0) {
		cout << "Country " << country << " has capital ";
		cout << countries_and_capitals[country];
		cout << endl;
	}
	else {
		cout << "Country " << country << " doesn't exist" << endl;
	}
}


void Dump(const map<string, string>& countries_and_capitals){
	if (!countries_and_capitals.empty()) {
		for (const auto& item: countries_and_capitals) {
			cout << item.first << "/" << item.second << " ";
		}
		cout << endl;
	}
	else {
		cout << "There are no countries in the world" << endl;
	}
}


int main() {
	map<string, string> countries_and_capitals;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;
		if (operation_code == "DUMP") {
			Dump(countries_and_capitals);
		}
		else if (operation_code == "ABOUT") {
			string country;
			cin >> country;
			About(countries_and_capitals, country);

		}
		else if (operation_code == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			Rename(countries_and_capitals, old_country_name, new_country_name);
		}
		else if (operation_code == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;
			ChangeCapital(countries_and_capitals, country, new_capital);
		}
	}
	return 0;
}