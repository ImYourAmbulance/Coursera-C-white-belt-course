#include <iostream>
#include <string>

using namespace std;

class ReversibleString {
  public:
	ReversibleString (const string& s) {
		word = s;
	}
	ReversibleString () {
		word = "";
	}
	string ToString() const {
		return word;
	}
	void Reverse() {
		string result;
		for (const auto& ch : word) {
			result.insert(result.begin(), ch);
		}
		word = result;
	}
  private:
	string word;
};


int main() {

	return 0;
}