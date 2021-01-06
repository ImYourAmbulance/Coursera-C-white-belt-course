#include <iostream>
#include <sstream>
#include <iostream>
#include <exception>

using namespace std;
string AskTimeServer();


class TimeServer {
public:
  string GetCurrentTime() {
	  try {
		  last_fetched_time = AskTimeServer();
	  } catch (system_error& ex) {
		  return last_fetched_time;
	  }
	  return last_fetched_time;
  }
private:
  string last_fetched_time = "00:00:00";
};

int main() {
	return 0;
}