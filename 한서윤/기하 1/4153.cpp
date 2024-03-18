#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if (a > b && a > c) {
			if (b * b + c * c == a * a)
				cout << "right" << '\n';
			else cout << "wrong" << '\n';
		}
		else if (b > a && b > c) {
			if (a * a + c * c == b * b)
				cout << "right" << '\n';
				else cout << "wrong" << '\n';
			}
		else if (c > a && c > b) {
				if (a * a + b * b == c * c)
					cout << "right" << '\n';
				else cout << "wrong" << '\n';
			}
	}
}