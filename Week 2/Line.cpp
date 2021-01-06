#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Worry(vector<bool>& queue, int i) {
	queue[i] = true;
}


void Quiet(vector<bool>& queue, int i) {
	queue[i] = false;
}


void Come(vector<bool>& queue, int k) {
	queue.resize(queue.size() + k);
}


void Worry_Count(const vector<bool>& queue) {
	int k = 0;
	for (auto person : queue) {
		if (person) {
			++k;
		}
	}
	cout << k << endl;
}


void Print_Vector(const vector<bool>& queue) {
	for (auto person : queue) {
		cout << person;
	}
	cout << endl;
}
int main() {
	vector<bool> queue;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string function_name;
		cin >> function_name;
		if (function_name == "WORRY_COUNT") {
			Worry_Count(queue);
		}
		else {
			int digit;
			cin >> digit;
			if (function_name == "QUIET") {
				Quiet(queue, digit);
			}
			else if (function_name == "COME") {
				Come(queue, digit);
			}
			else if (function_name == "WORRY") {
				Worry(queue, digit);
			}
		}
	}
	return 0;
}