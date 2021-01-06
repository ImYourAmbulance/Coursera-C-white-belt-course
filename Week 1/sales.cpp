#include <iostream>
using namespace std;

int main() {
	double n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;
	double end_sale = 0;
	if (n > a) {
		end_sale = x;
	}
	if (n > b) {
		end_sale = y;
	}
	cout << n*(1 - end_sale/100.0) << endl;
	return 0;
}
