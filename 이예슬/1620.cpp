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
		if (isdigit(s[0]))	//입력받은 값이 숫자일 경우
			cout << value[stoi(s) - 1] << "\n";
		else	//문자이면 바로 출력
			cout << list[s] << "\n";
	}
	return (0);
}