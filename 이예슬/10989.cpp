#include <iostream>

using namespace std;

int main(void)
{
	//���� ũ�Ⱑ 10000 �����̹Ƿ� ī���� ���� ���
	ios_base::sync_with_stdio(false);
	int n;
	int input;
	int arr[10001] = {0};
	int sort[10001];

	cin >> n;
	for (int i = 0; i < n; i++)	//�Է¹��� �� ���� ������ �迭�� ����
	{
		cin >> input;
		arr[input]++;
	}
	for (int i = 0; i < 10001; )	//�� ���� ������ ���� ���
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