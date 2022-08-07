#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, count;
	vector<int> v;
	vector<pair<int, int>> rank;
	vector<int> input;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		input.push_back(a);
	}
	vector<int> sorted(input);
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	for (int i = 0; i < n; i++)
		cout << lower_bound(sorted.begin(), sorted.end(), input[i]) - sorted.begin() << " ";
	return (0);
}