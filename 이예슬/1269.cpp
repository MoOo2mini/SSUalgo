#include <iostream>
#include <map>
using namespace std;

//Ư�� ���� ���� ���θ� ã�� ���� map�� ����
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	int count = 0;
	map<int, int> set;

	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		int input;
		cin >> input;
		set[input]++;
	}
	for (int i = 0; i < b; i++)
	{
		int input;
		cin >> input;
		if (set[input])
			count++;
	}
	cout << a + b - count * 2;
	return (0);
}