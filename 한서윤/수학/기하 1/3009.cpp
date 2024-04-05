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

	int x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	if (x1 == x2) {
		x4 = x3;
		if (y1 == y3) y4 = y2;
		else y4 = y1;
	}
	else if (x1 == x3) {
		x4 = x2;
		if (y1 == y2) y4 = y3;
		else y4 = y1;
	}
	else {
		x4 = x1;
		if (y2 == y1) y4 = y3;
		else y4 = y2;
	}
	cout << x4 << " " << y4;
}