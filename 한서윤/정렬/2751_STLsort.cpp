#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	int* num = new int[n];
	for (int i = 0; i < n; i++) cin >> num[i];
	
	sort(num, num+n);

	for (int i = 0; i < n; i++) cout << num[i] << '\n';
	delete[] num;
}