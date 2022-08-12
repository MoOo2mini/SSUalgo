#include <iostream>
#define MAX 15

using namespace std;

int arr[MAX];
int n;
int count = 0;

bool ispromising(int num, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if (arr[i] == num || abs(num -arr[i])/(float)(cnt - i) == 1)
			return false;
	}
	return true;
}

void dfs(int cnt)
{
	if (cnt == n)
	{
		count++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!ispromising(i, cnt))
			continue;
		arr[cnt] = i;
		dfs(cnt + 1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dfs(0);
	cout << count;
	return (0);
}