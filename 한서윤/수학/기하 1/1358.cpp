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

	int w, h, x, y, p, cnt = 0;
	cin >> w >> h >> x >> y >> p;
	double r = h / 2;
	
	for (int i = 0; i < p; i++) {
		int px, py, pd;
		cin >> px >> py;
		if (x <= px && px <= (x + w) && y <= py && py <= (y + h)) cnt++;
		else if (px < x) {
			pd = (px - x) * (px - x) + (py - (y + r)) * (py - (y + r));
			if (pd <= r * r) cnt++;
		}
		else if (px > (x + w)) {
			pd = (px - (x + w)) * (px - (x + w)) + (py - (y + r)) * (py - (y + r));
			if (pd <= r * r) cnt++;
		}
	}
	cout << cnt;
}