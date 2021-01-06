#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class FunctionPart {
public:
  FunctionPart(char new_operation, double new_value) {
    operation = new_operation;
	value = new_value;
  }
  void Invert() {
    if (operation == '+') {
    	operation = '-';
    }
    else if (operation == '-') {
    	operation = '+';
    }
    else if (operation == '/') {
    	operation = '*';
    }
    else {
    	operation = '/';
    }
  }
  double Apply(double new_value) const {
    if (operation == '+') {
      return (new_value + value);
    }
    else if (operation == '-') {
    	return (new_value - value);
    }
    else if (operation == '*') {
    	return (new_value * value);
    }
    else {
    	return (new_value / value);
    }
  }
private:
  char operation;
  double value;
};
class Function {
public:
  void AddPart(char operation, double value) {
    parts.push_back({operation, value});
  }
  double Apply(double value) const  {
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