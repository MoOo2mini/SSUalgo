#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string a, b;
	string ans;
	int carry = 0;
	int diff;
	char num;

	cin >> a >> b;

	//a, b �� ���̰� �� �� �� a, ª�� �� b�� �ٲ�
	if (a.length() < b.length())
		swap(a, b);
	diff = a.length() - b.length();

	//b �տ� '0'�� �߰��� a, b�� �ڸ����� ������
	for (int i = 0; i < diff; i++)
	{
		b.insert(0, "0");
	}

	//a, b�� �ڿ������� ���ڸ��� ���ؼ� ans�� ����
	for (int i = a.length() - 1; i >= 0; i--)
	{
		num = a[i] + b[i] - '0' + carry;
		if (num > '9')
		{
			carry = 1;
			num -= 10;
		}
		else
			carry = 0;
		ans += num;
	}
	if (carry == 1)
		ans += '1';
	reverse(ans.begin(), ans.end());
	cout << ans;
	return (0);
}