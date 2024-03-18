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

	int num, d[6], l[6], w;
	cin >> num;
	for (int i = 0; i < 6; i++) cin >> d[i] >> l[i];
	if (d[0] == d[2]) {
		if (d[1] == d[3]) w = (l[0] + l[2]) * (l[1] + l[3]) - l[1] * l[2];
		else  w = (l[0] + l[2]) * l[3] - l[0] * l[1];
	}
	else {
		if (d[1] == d[3]) w = l[0] * (l[1] + l[3]) - l[2] * l[3];
		else  w = l[0] * l[1] - (l[0] - l[2]) * l[3];
	}
	cout << num * w;
}