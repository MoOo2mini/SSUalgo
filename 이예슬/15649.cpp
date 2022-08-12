#include <iostream>
#include <vector>

using namespace std;

bool visited[8];
vector<int> ans;
int n, m;

void print()
{
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
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
		if (visited[i])
			continue;
		visited[i] = true;
		ans.push_back(i + 1);
		dfs(cnt + 1);
		ans.pop_back();
		visited[i] = false;
	}
}

int main(void)
{
	int cnt;

	cin >> n >> m;
	for (int i = 0; i < 8; i++)
	{
		visited[i] = false;
	}
	dfs(0);
	return (0);
}