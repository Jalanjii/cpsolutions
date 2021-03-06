#include <iostream>
#include <cmath>

using namespace std;

int fasteuc(int a, int b) {
	int l, j, rem;
	if (a == b) { return a; }
	if (a > b) { l = a; j = b; }
	else { l = b; j = a; }
	if (j == 0) { return l; }
	if (l%j == 0) { return j; }

	if (!(l % 2) && j % 2 == 0) {
		l = l / 2; j = j / 2;
		return fasteuc(l, j) * 2;

	}
	else if (l % 2 != 0 && j % 2 != 0) {
		l = l; j = (l - j) / 2;
		
	}
	else {
		if (l % 2 == 0) { l = l / 2; j = j; }
		else { l = l; j = j / 2; }

	}
	rem = l % j;
	l = j;
	j = rem;
	return fasteuc(l, j);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	cout << fasteuc(a, b);
	return 0;
}
