#include <iostream>
#define MAX 8

using namespace std;

int n, m;
int arr[MAX];

void dfs(int cnt, int num)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = num; i < n; i++)
	{
		arr[cnt] = i + 1;
		dfs(cnt + 1, i);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dfs(0, 0);
	return (0);
}