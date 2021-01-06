#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool String_comparison(string s1, string s2) {
	for (auto& ch : s1) {
		ch = tolower(ch);
	}
	for (auto& ch : s2) {
		ch = tolower(ch);
	}
	return (s1 < s2);
}

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (auto& item : v) {
		string x;
		cin >> x;
		item = x;
	}
	sort(begin(v), end(v), String_comparison);
	for (const auto& item : v) {
		cout << item << " ";
	}
	cout << endl;
	return 0;
}