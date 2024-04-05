#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int fact(int n);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, result;
	cin >> n;
	result = fact(n);
	cout << result;
}

int fact(int n) {
	int ans;
	if (n == 0) ans = 1;
	else ans = n * fact(n - 1);
	return ans;
}