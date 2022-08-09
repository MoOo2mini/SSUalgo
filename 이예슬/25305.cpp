#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, k, input;
	vector<int> score;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		score.push_back(input);
	}
	sort(score.begin(), score.end(), greater<int>());
	cout << score[k - 1];
	return (0);
}