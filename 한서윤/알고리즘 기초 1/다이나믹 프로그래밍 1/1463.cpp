#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n[1000001] = { 0, };
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	for (int i = 2; i <= 1000000; i++) {
		n[i] = n[i - 1] + 1;
		if (i % 3 == 0) n[i] = min(n[i / 3] + 1, n[i]);
		if (i % 2 == 0) n[i] = min(n[i / 2] + 1, n[i]);
	}
	int x;
	cin >> x;
	cout << n[x];
}