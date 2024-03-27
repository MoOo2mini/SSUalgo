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

	double r;
	cin >> r;
	cout << fixed;
	cout.precision(6);
	cout << r * r * 3.14159265358979 << '\n';
	cout << r * r * 2;
}