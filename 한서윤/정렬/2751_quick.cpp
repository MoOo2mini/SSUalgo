#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* quick���� �����غ����� ������ �̰� �־��� ��� O(n^2)�� �� ���������� ���� ... �� ���������� ����� ��
void quick(int num[], int left, int right);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	int* num = new int[n];
	for (int i = 0; i < n; i++) cin >> num[i];
	
	quick(num, 0, n - 1);

	for (int i = 0; i < n; i++) cout << num[i] << '\n';
	delete [] num;
}

void quick(int num[], int left, int right) {
	int low = left + 1, high = right, pivot = left;
	if (left >= right) return;
	while (low <= high) {
		while (num[low] < num[pivot] && low < right) low++;
		while (num[high] > num[pivot] && high >= left) high--;
		if (low <= high) swap(num[low], num[high]);
		if (low == high) break;
	}
	swap(num[high], num[pivot]);
	swap(high, pivot);

	quick(num, left, pivot-1);
	quick(num, pivot + 1, right);
}
*/