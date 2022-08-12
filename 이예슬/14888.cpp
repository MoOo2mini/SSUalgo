#include <iostream>
#define MAX 100

using namespace std;
int arr[MAX];
int oper_arr[MAX];
int oper[4];
int max = -1000000000;
int min = 1000000000;
int sum;

int cal_sum(int n)
{
	sum = arr[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (oper_arr[i] == 0)
			sum += arr[i + 1];
		else if (oper_arr[i] == 1)
			sum -= arr[i + 1];
		else if (oper_arr[i] == 2)
			sum *= arr[i + 1];
		else if (oper_arr[i] == 3)
			sum /= arr[i + 1];
	}
	return (sum);
}

void cal(int n, int cnt)
{
	if (cnt == n - 1)
	{
		//값 계산해서 최대 혹은 최소인지 체크
		sum = cal_sum(n);
		if (sum > ::max)
			::max = sum;
		if (sum < ::min)
			::min = sum;
	}
	for (int i = 0; i < 4; i++)
	{
		if (oper[i]!= 0)
		{
			oper[i]--;
			oper_arr[cnt] = i;
			cal(n, cnt + 1);
			oper[i]++;
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
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	cal(n, 0);
	cout << ::max << "\n"
			 << ::min;
	return (0);
}