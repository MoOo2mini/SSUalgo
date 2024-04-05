#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* quick부터 구현해보려고 했으나 이건 최악의 경우 O(n^2)라서 이 문제에서는 실패 ... 앞 문제에서는 통과됨 ㅎ
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