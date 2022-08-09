#include <iostream>

using namespace std;

int main(void)
{
	//수의 크기가 10000 이하이므로 카운팅 정렬 사용
	ios_base::sync_with_stdio(false);
	int n;
	int input;
	int arr[10001] = {0};
	int sort[10001];

	cin >> n;
	for (int i = 0; i < n; i++)	//입력받은 각 값의 개수를 배열에 저장
	{
		cin >> input;
		arr[input]++;
	}
	for (int i = 0; i < 10001; )	//각 값의 개수에 따라 출력
	{
		if (arr[i] == 0)
			i++;
		else
		{
			cout << i << "\n";
			arr[i]--;
		}
	}
	return (0);
}