#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class FunctionPart {
public:
  FunctionPart(const char& new_operation, const double& new_value) {
    operation = new_operation;
	value = new_value;
  }
  void Invert() {
    operation == '+' ? operation = '-' : operation = '+';
  }
  double Apply(const double& new_value) {
    if (operation == '+') {
      return (new_value + value);
    }
    else {
    	return (new_value - value);
    }
  }
private:
  char operation;
  double value;
};
class Function {
public:
  void AddPart(const char& operation, const double& value) {
    parts.push_back({operation, value});
  }
  double Apply(double& value) {
    for (const FunctionPart& part : parts) {
      value = part.Apply(value);
    }
    return value;
  }
  void Invert() {
    for (FunctionPart& part : parts) {
    	part.Invert();
    }
    reverse(begin(parts), end(parts));
  }
private:
  vector<FunctionPart> parts;
};





int main() {
  return 0;
}