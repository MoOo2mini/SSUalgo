#include <iostream>
#define MAX 20

using namespace std;

int arr[MAX][MAX];
bool visited[MAX];
int team1[MAX / 2];
int team2[MAX / 2];
int min = 40000;

void s(int n, int cnt, int start)
{
	if (cnt == n/2)
	{
		int sum1 = 0;
		int sum2 = 0;
		int idx1 = 0;
		int idx2 = 0;
	
		for (int i = 0; i < n; i++)	//팀 멤버 정하기
		{
			if (visited[i])
			{
				team1[idx1] = i;
				idx1++;
			}
			else
			{
				team2[idx2] = i;
				idx2++;
			}
		}
		for (int i = 0; i < n / 2; i++)	//팀 능력치 계산
		{
			for (int j = 0; j < n / 2; j++)
			{
				sum1 += arr[team1[i]][team1[j]];
				sum2 += arr[team2[i]][team2[j]];
			}
		}
		if (abs(sum1 - sum2) < ::min) //최소 차이 계산
			::min = abs(sum1 - sum2);
		return;
	}
	for (int i = start; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			s(n, cnt + 1, i + 1);
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	s(n, 0, 0);
	cout << ::min;
	return (0);
}