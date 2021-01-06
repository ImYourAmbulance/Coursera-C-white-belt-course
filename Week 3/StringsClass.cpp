#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    string tmp = s;
    strings.push_back(s);
  }
  vector<string> GetSortedStrings() {
    SortStrings();
    return strings;
  }
private:
  vector<string> strings;
  void SortStrings() {
	  sort(strings.begin(), strings.end());
  }

};

int main() {
	return 0;
}