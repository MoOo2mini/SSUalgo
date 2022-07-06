#include <iostream>
using namespace std;

enum Place
{
	u, d
};

int find_maxSum(int **d, int n)
{

	int **a = d;
	for (int i = 2; i <= n; i++) {
		d[0][i] = max(d[1][i - 1], d[1][i - 2]) + a[0][i + 1];
		d[1][i] = max(d[0][i - 1], d[0][i - 2]) + a[1][i + 1];
	}

	return max(d[n][0], d[n][1]);
}

int main()
{
	int T;
	int n;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;
		int nums[n + 1][2];

		nums[0][0] = 0;
		nums[0][1] = 0;

		for (int j = 1; j <= n; j++)
			cin >> nums[j][u];
		for (int j = 1; j <= n; j++)
			cin >> nums[j][d];
		// cout << find_maxSum(nums, n);
	}
}

//참고 링크 : https://m.blog.naver.com/occidere/220786307316