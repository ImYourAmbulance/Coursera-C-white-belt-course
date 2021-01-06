#include <iostream>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

void EnsureEqual(const string& left, const string& right) {
	if (left != right) {
		stringstream message;
		message << left << " != " << right;
		throw runtime_error(message.str());
	}
}


int main() {

  return 0;
}