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

	//a, b 중 길이가 더 긴 걸 a, 짧은 걸 b로 바꿈
	if (a.length() < b.length())
		swap(a, b);
	diff = a.length() - b.length();

	//b 앞에 '0'을 추가해 a, b의 자릿수를 맞춰줌
	for (int i = 0; i < diff; i++)
	{
		b.insert(0, "0");
	}

	//a, b를 뒤에서부터 한자리씩 더해서 ans에 저장
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