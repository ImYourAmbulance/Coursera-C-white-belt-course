#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <exception>
#include <iomanip>
#include <typeinfo>

using namespace std;

class Date {
public:
	Date() = default;
	Date(int y, int m, int d) {
		// if month is invalid of month and day are invalid we say month is invalid
		if ((!(m >= 1 && m <= 12) && !(d >= 1 && d <= 31)) || (!(m >= 1 && m <= 12) && (d >= 1 && d <= 31))) {
			stringstream err;
			err << "Month value is invalid: " + to_string(m);
			throw runtime_error(err.str());
		}
		else if ((m >= 1 && m <= 12) && !(d >= 1 && d <= 31)) {
			stringstream err;
			err << "Day value is invalid: " + to_string(d);
			throw runtime_error(err.str());
		}
		else {
			this->day = d;
			this->month = m;
			this->year = y;
		}
	}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() != rhs.GetYear()) return (lhs.GetYear() < rhs.GetYear());
	else {
		if (lhs.GetMonth() != rhs.GetMonth()) return (lhs.GetMonth() < rhs.GetMonth());
		else return (lhs.GetDay() < rhs.GetDay());
	}
}

class Database {
public:
	Database() = default;
	void AddEvent(const Date& date, const string& event) {
		dates.insert(date);
		// making sure whether the event exists or not
		int search = dict[date].count(event);
		// invalid comparison below
		bool already_exist = (search != 0) ? true : false;
		if (!already_exist) dict[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		int search = dict[date].count(event);
		bool event_exist = (search != 0) ? true : false;

		if (event_exist) {
			// provided only 1 event exists then after deleting this event
			// we must delete date from dates too
			if (dict[date].size() == 1) dates.erase(date);
			dict[date].erase(event);
			//cout << "Deleted successfully" << endl;
		}
		return event_exist;
	}
	int  DeleteDate(const Date& date) {
		// counting number of event at a particular date
		int count = 0;
		auto events = dict[date];
		for (auto element : events) ++count;
		// clearing the set of events
		dict[date].clear();
		dates.erase(date);
		// returning the number of deleted events
		return count;
	}
	void Find(const Date& date) const {
		// searching for the date the we are given
		int search = dates.count(date);
		bool date_exist = (search != 0) ? true : false;
		// dict.at[date] can throw an exception if date doesnt exist
		if (date_exist) {
			set<string> events = dict.at(date);
			for (string element : events) {
				cout << element << endl;
			}
		}
	}
	void Print() const {
		for (const Date& element : dates) {
			// .at may throw an exception
			set<string> events = dict.at(element);
			for (const string& event : events) {
				cout << setfill('0');
				cout << setw(4) << element.GetYear() << "-" << setw(2) << element.GetMonth() << "-" << setw(2) << element.GetDay() << " ";
				// potential threat
				cout << event << endl;
				cout << setfill(' ');
			}
		}
	}

private:
	map<Date, set<string>> dict;
	set<Date> dates;
};
bool EnsureEmDashAndSkip(stringstream& line) {
	char symb = line.peek();
	line.ignore(1);
	return (symb == '-');
}
Date ReadDate(string& date_str) {
	stringstream line;
	// If onlyEmDash is false that means that there is at least one not EmDash symbol (-) between numberes
	bool onlyEmDash = true;
	line << date_str;
	int year, month, day;
	line >> year;
	// If EnsureEmDashAndSkip returns false then there is wrong date formmat
	onlyEmDash *= EnsureEmDashAndSkip(line);
	line >> month;
	onlyEmDash *= EnsureEmDashAndSkip(line);
	line >> day;
	if (line && onlyEmDash && line.eof()) {
		Date date(year, month, day);
		return date;
	}
	else {
		// if there is a problem with line, meaning date_str has wrong format
		// we will throw the exception 
		stringstream exc;
		exc << "Wrong date format: " << date_str;
		throw runtime_error(exc.str());
	}
}


void HandleCommand(const string& command, Database& db) {
	if (command.empty()) return;
	stringstream line;
	line << command;
	string type;
	line >> type;
	if (type == "Add") {
		string date_str;
		line >> date_str;
		// potential problem
		Date date = ReadDate(date_str);
		string event;
		line >> event;
		db.AddEvent(date, event);
	}
	else if (type == "Del") {
		// Idk yet how to distinguish Del with an event and without one
		string date_str;
		line >> date_str;
		// potential problem
		Date date = ReadDate(date_str);
		string event;
		line >> event;
		if (line) {
			bool deleted;
			deleted = db.DeleteEvent(date, event);
			if (deleted) cout << "Deleted successfully" << endl;
			else cout << "Event not found" << endl;
		}
		else {
			int num_of_deleted;
			num_of_deleted = db.DeleteDate(date);
			cout << "Deleted " + to_string(num_of_deleted) + " events" << endl;
		}
	}
	else if (type == "Print") {
		db.Print();
	}
	else if (type == "Find") {
		string date_str;
		line >> date_str;
		// potential problem
		Date date = ReadDate(date_str);
		db.Find(date);
	}
	else {
		stringstream exc;
		exc << "Unknown command: " << command;
		throw runtime_error(exc.str());
	}
	return;
}


int main() {
	
	Database db;

	string command;
	while (getline(cin, command)) {
		try {
			HandleCommand(command, db);
		}
		catch (runtime_error& exc) {
			cout << exc.what() << endl;
		}
	}
	
	return 0;
}
