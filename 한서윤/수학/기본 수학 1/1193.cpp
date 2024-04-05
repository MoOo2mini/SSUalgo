#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int x, line = 1;
	cin >> x;
	while (x > 0) {
		x -= line;
		line++;
	}
	line--;
	if (line % 2 == 0)
		cout << line + x << "/" << -x + 1;
	else
		cout << -x + 1 << "/" << line + x;
}