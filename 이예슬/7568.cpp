#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;

	cin >> n;
	int rank[n] = {0};
	pair<int, int> p[n];	//pair 형식 배열에 키, 몸무게 같이 저장
	// int weight[n];
	// int height[n];
	int count;
	for (int i = 0; i < n; i++)
		// cin >> weight[i] >> height[i];
		cin >> p[i].first >> p[i].second;

	for (int i = 0; i < n; i++)
	{
		count = 1;
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			// if (weight[i] < weight[j] && height[i] < height[j])
			if (p[i].first < p[j].first && p[i].second < p[j].second)
				count++;
		}
		rank[i] = count;
	}
	for (int i = 0; i < n; i++)
	{
		cout << rank[i] << " ";
	}
	return (0);
}