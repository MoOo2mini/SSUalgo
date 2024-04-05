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

	int n, min, max;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (i == 0) min = num, max = num;
		if (num > max) max = num;
		else if (num < min) min = num;
	}
	cout << min * max;
}