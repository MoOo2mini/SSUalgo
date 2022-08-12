#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> ans;

void print()
{
	for (int i = 0; i < m; i++)
		cout << ans[i] << " ";
	cout << "\n";
}

void dfs(int cnt, int start)
{
	if (cnt == m)
	{
		print();
		return;
	}
	for (int i = start; i < n; i++)
	{
		ans.push_back(i + 1);
		dfs(cnt + 1, i + 1);
		ans.pop_back();
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