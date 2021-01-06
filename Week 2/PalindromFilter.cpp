//============================================================================
#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool IsPalindrom(string s) {
	if (s == "") {
		return true;
	}
	else {
		for (int i = 0; i < (s.size() / 2 + 1); ++i)  {
			if (s[i] != s[s.size() - i - 1]) {
				return false;
			}
		}
		return true;
	}
}


vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> new_words;
	for (auto a : words) {
		if (a.size() >= minLength && IsPalindrom(a)) {
			new_words.push_back(a);
		}
	}
	return new_words;
}
int main() {
	return 0;
}