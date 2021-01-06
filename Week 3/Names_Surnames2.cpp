#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


string FindNameByYear(const map<int, string>& names, int year) {
	string name;
	for (const auto& item : names) {
	    // если очередной год не больше данного, обновляем имя
	    if (item.first <= year) {
	      name = item.second;
	    }
	    else {
	      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
	      break;
	    }
	}
	return name;
}

void SortVector(vector<string>& names, string cur_name) {
	int i = 0;
	while (i < names.size() - 1) {
		if (names[i] == names[i+1]) {
			names.erase(names.begin() + i);
			--i;
		}
		++i;
	}
	if (names.front() == cur_name) {
		names.erase(names.begin());
	}

}


string Beatiful_list(const vector<string> names) {
	string res = "(";
	for (const auto& item : names) {
		res += item + ", ";
	}
	res = res.substr(0, res.size() - 2);
	res += ")";
	return res;
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		first_names[year] = first_name;
	}

	void ChangeLastName(int year, const string& last_name) {
		last_names[year] = last_name;
	}
	string GetFullName(int year) {
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);
		if (first_name.empty() && last_name.empty()) {
			return ("Incognito");
		}
		else if (last_name.empty()) {
			return (first_name + " with unknown last name");
		}
		else if (first_name.empty()) {
			return (last_name + " with unknown first name");
		}
		else {
			return (first_name + " " + last_name);
		}
	}
	string GetFullNameWithHistory(int year) {
		string first_name = FindNameByYear(first_names, year);
		string last_name = FindNameByYear(last_names, year);
		vector<string> first_vector;
		vector<string> last_vector;
		int k = 0;
		for (const auto& item : first_names) {
			if (item.first <= year) {
				++k;
				first_vector.insert(first_vector.begin(), item.second);
			}
			else {
				break;
			}
		}
		//cout << k << endl;
		if (k > 1) {
			SortVector(first_vector, first_name);
		}
		else if (k == 1){
			first_vector.pop_back();
		}
		k = 0;
		for (const auto& item : last_names) {
			if (item.first <= year) {
				++k;
				last_vector.insert(last_vector.begin(), item.second);
			}
			else {
				break;
			}
		}
		//cout << k << endl;
		if (k > 1) {
			SortVector(last_vector, last_name);
		}
		else if (k == 1){
			last_vector.pop_back();
		}
		// first_vector, last_vector, first_name, last_name
		// надо сделать (порб, морг, ангар)
		if (last_name.empty() && first_name.empty()) {
			return "Incognito";
		}
		else if (first_name.empty()) {
			if (last_vector.empty()) {
				return (last_name + " with unknown first name");
			}
			else {
				string last_list = Beatiful_list(last_vector);
				return (last_name + " " + last_list + " with unknown first name");
			}
		}
		else if (last_name.empty()) {
			if (first_vector.empty()) {
				return (first_name + " with unknown last name");
			}
			else {
				string first_list = Beatiful_list(first_vector);
				return (first_name + " " + first_list  + " with unknown last name");
			}
		}
		else {
			if (first_vector.empty() && last_vector.empty()) {
				return (first_name + " " + last_name);
			}
			else if (first_vector.empty()) {
				string last_list = Beatiful_list(last_vector);
				return (first_name + " " + last_name + " " + last_list);
			}
			else if (last_vector.empty()) {
				string first_list = Beatiful_list(first_vector);
				return (first_name + " " + first_list + " " + last_name);
			}
			else {
				string first_list = Beatiful_list(first_vector);
				string last_list = Beatiful_list(last_vector);
				return (first_name + " " + first_list + " " + last_name + " " + last_list);
			}
		}

	}

private:
	map<int, string> first_names;
	map<int, string> last_names;
};



int main() {

	return 0;
}
