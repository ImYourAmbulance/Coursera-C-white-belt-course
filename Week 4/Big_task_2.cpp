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

Rational operator+(Rational first, Rational second) {
	int p1 = first.Numerator();
	int p2 = second.Numerator();
	int q1 = first.Denominator();
	int q2 = second.Denominator();
	int new_denominator = (q1 * q2) / FindMCD(q1, q2);
	int new_numerator = p1 * (new_denominator / q1) + p2 * (new_denominator / q2);
	return Rational(new_numerator, new_denominator);
}

Rational operator-(Rational first, Rational second) {
	int p1 = first.Numerator();
	int p2 = second.Numerator();
	int q1 = first.Denominator();
	int q2 = second.Denominator();
	int new_denominator = (q1 * q2) / FindMCD(q1, q2);
	int new_numerator = p1 * (new_denominator / q1) - p2 * (new_denominator / q2);
	return Rational(new_numerator, new_denominator);
}

bool operator==(Rational first, Rational second) {
	return ((first.Numerator() == second.Numerator()) &&
			(first.Denominator() == second.Denominator()));
}

int main() {

	return 0;
}