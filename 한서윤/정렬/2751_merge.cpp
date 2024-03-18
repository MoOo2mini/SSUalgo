#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void partition(int num[], int left, int right);
void merge(int num[], int left, int mid, int right);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	int* num = new int[n];
	for (int i = 0; i < n; i++) cin >> num[i];
	partition(num, 0, n - 1);

	for (int i = 0; i < n; i++) cout << num[i] << '\n';
	delete[] num;
}

void partition(int num[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		partition(num, left, mid);
		partition(num, mid + 1, right);
		merge(num, left, mid, right);
	}
}

void merge(int num[], int left, int mid, int right) {
	int* sort = new int[right + 1];
	int idx = left, idx1 = left, idx2 = mid + 1;
	while (idx1 <= mid && idx2 <= right) {
		if (num[idx1] > num[idx2]) sort[idx++] = num[idx2++];
		else sort[idx++] = num[idx1++];
	}
	if (idx1 > mid) // 1의 원소 모두 정렬 (2는 남음)
		while (idx2 <= right) sort[idx++] = num[idx2++];
	else // 반대
		while (idx1 <= mid) sort[idx++] = num[idx1++];
	
	for (int i = left; i <= right; i++)
		num[i] = sort[i];
	delete[] sort;
}