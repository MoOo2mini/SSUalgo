#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int m = n / 2;

	if (k > m * (n - m))
	{
		cout << -1 << '\n';
		return 0;
	}

	string ab = "";
	for (int i = 0; i < n; i++) // B로 모두 채운다.
		ab += 'B';

	if (k == 0) // 0일 때 예외 처리
	{
		ab[n - 1] = 'A';
		cout << ab << '\n';
		return 0;
	}

	int b = n; // A, B의 개수 초기화
	int a = 0;
	while (true)
	{
		if (a * b >= k)
		{
			for (int i = 0; i < a - 1; i++) // 앞에서부터 A의 개수 - 1 개를 A로 채운다.
				ab[i] = 'A';

			int c = (a - 1) * b; // A의 개수 - 1 * B의 개수를 저장 (마지막에 들어갈 A를 제외한 개수)
			int r = k - c; // 마지막 A를 이용하여 채워야할 쌍의 개수
			ab[(n - 1) - r] = 'A'; // 마지막 인덱스에서 r개 앞에 A를 넣는다.

			break;
		}
		else
		{
			b--; // A, B의 개수 조정
			a++;
		}
	}

	cout << ab << '\n';
