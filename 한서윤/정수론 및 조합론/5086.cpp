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

	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		if (b % a == 0) cout << "factor" << '\n';
		else if (a % b == 0) cout << "multiple" << '\n';
		else cout << "neither" << '\n';
	}
}