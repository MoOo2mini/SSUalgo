#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string str;
	int n = 0;
	while (cin >> str) n++;
	cout << n;
}