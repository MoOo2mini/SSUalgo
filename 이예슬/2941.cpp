#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	long long i;
	int count = 0;
	int count_dz = 0;

	cin >> s;
	i = -2;
	while (1)
	{
		i = s.find("c=", i + 2);
		if (i == string::npos)
			break;
		count++;
	}
	i = -2;
	while (1)
	{
		i = s.find("c-", i + 2);
		if (i == string::npos)
			break;
		count++;
	}
	i = -3;
	while (1)
	{
		i = s.find("dz=", i + 3);
		if (i == string::npos)
			break;
		count++;
		count_dz++;
	}
	i = -2;
	while (1)
	{
		i = s.find("d-", i + 2);
		if (i == string::npos)
			break;
		count++;
	}
	i = -2;
	while (1)
	{
		i = s.find("lj", i + 2);
		if (i == string::npos)
			break;
		count++;
	}
	i = -2;
	while (1)
	{
		i = s.find("nj", i + 2);
		if (i == string::npos)
			break;
		count++;
	}
	i = -2;
	while (1)
	{
		i = s.find("s=", i + 2);
		if (i == string::npos)
			break;
		count++;
	}
	i = -2;
	while (1)
	{
		i = s.find("z=", i + 2);
		if (i == string::npos)
			break;
		count++;
	}
	if (count_dz != 0)
		count -= count_dz;
	cout << s.length() - count - count_dz;
	return (0);
}