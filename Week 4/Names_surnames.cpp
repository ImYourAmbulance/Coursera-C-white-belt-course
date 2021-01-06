#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
	string name;
	string surname;
	int birth_day;
	int birth_month;
	int birth_year;
};

void Name(const int& code, const vector<Student>& students) {
	int i = 0;
	for (const auto& student : students) {
		++i;
		if (i == code) {
			cout << student.name << " " << student.surname << endl;
			return;
		}
	}
	cout << "bad request" << endl;
}
void Date(const int& code, const vector<Student>& students) {
	int i = 0;
	for (const auto& student : students) {
		++i;
		if (i == code) {
			cout << student.birth_day << "." << student.birth_month
				 << "." << student.birth_year << endl;
			return;
		}
	}
	cout << "bad request" << endl;
}
int main() {
	vector<Student> students;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name, surname;
		int day, month, year;
		cin >> name;
		cin >> surname;
		cin >> day;
		cin >> month;
		cin >> year;
		Student student = {name, surname, day, month, year};
		students.push_back(student);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string operation;
		cin >> operation;
		int code;
		cin >> code;
		if (operation == "name") {
			Name(code, students);
		}
		else if (operation == "date") {
			Date(code, students);
		}
		else {
			cout << "bad request" << endl;
		}
	}
	return 0;
}
