#include <cmath>
#include <iostream>
using namespace std;

int main() {
	double a, b, c, discriminant;
	cin >> a >> b >> c;
	discriminant = b*b - 4*a*c;
	if (discriminant >= 0 && a != 0) {
	  double x1, x2;
	  x1 = (-b + sqrt(discriminant)) / (2*a);
	  x2 = (-b - sqrt(discriminant)) / (2*a);
	  if (x1 == x2) {
		  cout << x1;
	  }
	  else {
		  cout << x1 << " " << x2;
	  }
	}
	else {
	  if (discriminant >= 0 && a == 0 && b != 0) {
	    double x1;
	    x1 = -c / b;
	    cout << x1;
	  }
	}
	return 0;
}