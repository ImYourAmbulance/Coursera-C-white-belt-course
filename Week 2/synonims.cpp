#include <iostream>
#include <map>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	map<string,set<string>> synonims;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string operation_command;
		cin >> operation_command;
		if (operation_command == "COUNT") {
			string word;
			cin >> word;
			cout << synonims[word].size() << endl;
		}
		else if (operation_command == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;
			if (count(cbegin(synonims[word1]), cend(synonims[word1]), word2) &&
				count(cbegin(synonims[word2]), cend(synonims[word2]), word1)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else if (operation_command == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;
			synonims[word1].insert(word2);
			synonims[word2].insert(word1);
		}
	}
	return 0;
}