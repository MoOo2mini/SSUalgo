#include <iostream>

using namespace std;

int main(void)
{
	int cor[6] = {1, 1, 2, 2, 2, 8};
	int input;

	for (int i = 0; i < 6; i++)
	{
		cin >> input;
		cout << cor[i] - input << " ";
	}
	return (0);
}