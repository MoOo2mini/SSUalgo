#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, sum = 0;
	string num;
	cin >> n >> num;
	for (int i = 0; i < n; i++) {
		sum += num[i] - '0';
	}
	cout << sum;
}