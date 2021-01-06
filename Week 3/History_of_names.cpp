#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


struct Man {
	string name = "";
	string surname = "";
};


class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		history[year].name = first_name;
	}

	void ChangeLastName(int year, const string& last_name) {
		history[year].surname = last_name;
	}
	string GetFullName(int year) {
		string first_name;
		string last_name;
		for (const auto& item : history) {
			if (year >= item.first) {
				if (item.second.name != "") {
					first_name = item.second.name;
				}
				if (item.second.surname != "") {
					last_name = item.second.surname;
				}
			}
			else {
				break;
			}
		}
		if (first_name != "" and last_name != "") {
			return (first_name + " " + last_name);
		}
		else if (first_name != "" and last_name == "") {
			return (first_name + " with unknown last name");
		}
		else if (first_name == "" and last_name != "") {
			return (last_name + " with unknown first name");
		}
		else if (first_name == "" and last_name == "") {
			return ("Incognito");
		}
	}

private:
	map<int, Man> history;
};



int main() {
	
	return 0;
}