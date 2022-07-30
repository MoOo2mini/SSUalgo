#include <iostream>

using namespace std;

int main(void)
{
	int input;
	int n = 1;
	int line, top, bot;
	cin >> input;

	for (int i = 1; i <= input; i++)
	{
		if (n >= input)
		{
			line = i;
			break;
		}
		n += i + 1;
	}
	if (line % 2 == 1)
	{
		top = line - (input - (n - line + 1));
		bot = line + 1 - top;
	}
	else
	{
	top = input - (n - line + 1) + 1;
	bot = line + 1 - top;
	}
	cout << top << "/" << bot;
	return (0);
}