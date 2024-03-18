#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, count[8001] = { 0, }, cnt = 0, max = 0, avg, median, mode, first, end, check = 0;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		count[num + 4000]++;
		sum += num;

	}
	for (int i = 0; i <= 8000; i++) {
		while (count[i] != 0) {
			cnt++;
			if (max < count[i]) {
				max = count[i];
				mode = i - 4000;
				check = 1;
			}
			else if (max == count[i] && check == 1) {
				mode = i - 4000;
				check++;
			}
			if (cnt == 1) first = i - 4000;
			if (cnt == n / 2 + 1) median = i - 4000;
			if (cnt == n) end = i - 4000;
			count[i]--;
		}
	}
	avg = round(sum / n);
	if (avg == -0) avg = 0;

	cout << avg << '\n';
	cout << median << '\n';
	cout << mode << '\n';
	cout << end - first << '\n';
}