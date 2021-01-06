#include <iostream>
#include <string>
using namespace std;

int main() {
	int count = -2;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'f') {
			count ++;
		}
		if (count == 0) {
			cout << i;
			break;
		}
	}
	if (count < 0) {
		cout << count;
	}
	return 0;
}
