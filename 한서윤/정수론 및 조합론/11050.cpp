#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
int BC (int n, int k);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	cout << BC(n, k);
}

int BC (int n, int k) {
	if (n == k || k == 0) return 1;
	else return BC(n - 1, k - 1) + BC(n - 1, k);
}