#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void adjust(int num[], int root, int n);
void heap(int num[], int n);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	int* num = new int[n + 1];
	for (int i = 1; i <= n; i++) cin >> num[i];
	
	heap(num, n);

	for (int i = 1; i <= n; i++) cout << num[i] << '\n';
	delete[] num;
}

void adjust(int num[], int root, int n) {
	int x = num[root], i;
	for (i = 2 * root; i <= n; i *= 2) {
		if (i < n && num[i] < num[i + 1]) i++;
		if (x >= num[i]) break;
		num[i / 2] = num[i];
	}
	num[i / 2] = x;
}

void heap(int num[], int n) {
	for (int i = n / 2; i >= 1; i--) adjust(num, i, n);
	for (int i = n - 1; i >= 1; i--) {
		swap(num[1], num[i + 1]);
		adjust(num, 1, i);
	}
}