#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int t, h, w, n, x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;
		x = n / h + 1;
		y = n % h;
		if (y == 0) {
			x--;
			y = h;
		}
		cout << y;
		if (x < 10) cout << '0';
		cout << x << endl;
	}
}