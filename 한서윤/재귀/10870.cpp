#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int fibo(int n);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, result;
	cin >> n;
	result = fibo(n);
	cout << result;
}

int fibo(int n) {
	int ans;
	if (n == 0) ans = 0;
	else if (n == 1) ans = 1;
	else ans = fibo(n - 1) + fibo(n - 2);
	return ans;
}