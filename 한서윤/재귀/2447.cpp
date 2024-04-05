#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void star(int i, int j, int n);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			star(i, j, n);
		cout << '\n';
	}
}

void star(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) cout << " ";
	else {
		if (n / 3 == 0)
			cout << "*";
		else
			star(i, j, n / 3);
	}
}