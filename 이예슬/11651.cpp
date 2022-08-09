#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	vector<pair<int, int>> arr;
	int a, b;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr.push_back(make_pair(b, a));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].second << " " << arr[i].first << "\n";
	}
		return (0);
}