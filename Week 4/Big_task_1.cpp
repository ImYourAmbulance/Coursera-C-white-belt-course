#include <iostream>
using namespace std;

int FindMCD(int a, int b) {
    while (a != 0 && b != 0) {
    	if (a > b) {
    		a = a % b;
    	}
    	else {
    		b = b % a;
    	}
	}
    return (a + b);
}

int Signum(int a, int b) {
	int multip = a * b;
	if (multip > 0) {
		return 1;
	}
	else {
		return -1;
	}
}


class Rational {
public:
	Rational() {
		p = 0;
		q = 1;
	}
	Rational(int numerator, int denominator) {
		if (numerator != 0) {
			int MCD = FindMCD(abs(numerator), abs(denominator));
			int a = Signum(numerator, denominator);
			p = abs(numerator) / MCD * a;
			q = (abs(denominator) / MCD);
		}
		else {
			p = 0;
			q = 1;
		}
	}
	int Numerator() const {
		return p;
	}
	int Denominator() const {
		return q;
	}

private:
	int p;
	int q;
};


int main() {
	return 0;
}