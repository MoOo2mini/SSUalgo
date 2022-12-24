#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	map<string, int> list;
	string s;

	cin >> n >> m;
	string value[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		list[s] = i + 1;
		value[i] = s;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (isdigit(s[0]))	//�Է¹��� ���� ������ ���
			cout << value[stoi(s) - 1] << "\n";
		else	//�����̸� �ٷ� ���
			cout << list[s] << "\n";
	}
	return (0);
}