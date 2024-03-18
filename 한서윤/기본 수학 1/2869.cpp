#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int a, b, v, x, day = 1;
	cin >> a >> b >> v;
	x = (v - a) % (a - b);
	day += (v - a) / (a - b);
	if (x != 0) day++;
	cout << day;
}