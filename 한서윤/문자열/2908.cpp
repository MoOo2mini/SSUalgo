#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string a, b;
	char c;
	cin >> a >> b;
	swap(a[0], a[2]);
	swap(b[0], b[2]);
	stoi(a);
	stoi(b);
	if (a > b) cout << a;
	else cout << b;
}