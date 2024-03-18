#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string n;
	cin >> n;
	int length = n.length();
	int* num = new int[length];
	for (int i = 0; i < length; i++) {
		num[i] = n[i] - '0';
	}
	sort(num, num + length);
	for (int i = length; i > 0; i--)
		cout << num[i - 1];
}