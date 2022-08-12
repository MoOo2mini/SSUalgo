#include <iostream>
#define MAX 8

using namespace std;

int n, m;
int arr[MAX];

void print()
{
	for (int i = 0; i < m; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void dfs(int cnt)
{
	if (cnt == m)
	{
		print();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		arr[cnt] = i + 1;
		dfs(cnt + 1);
	}
}

int main(void)
{
	cin >> n >> m;

	dfs(0);
	return (0);
}