#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, int> BuildCharCounters(string word) {
	map<char, int> char_container;
	for (auto character : word) {
		++char_container[character];
	}
	return char_container;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
	  string first_word, second_word;
	  cin >> first_word >> second_word;
	  string result = "NO";
	  if (BuildCharCounters(first_word) == BuildCharCounters(second_word)) {
	    result = "YES";
	  }
	  cout << result << endl;
	}
	return 0;
}