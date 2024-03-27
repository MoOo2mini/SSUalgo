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

	int x, y, w, h, min;
	cin >> x >> y >> w >> h;
	if (x <= w / 2) {
		min = x;
	}
	else min = w - x;
	if (y <= h / 2 && y < min) min = y;
	else if (y > h / 2 && h - y < min) min = h - y;
	cout << min;
}