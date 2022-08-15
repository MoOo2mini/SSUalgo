#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	map<int, int> card;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (card.find(input) != card.end())	//같은 키가 존재하는 경우
			card[input]++;
		else
			card[input] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		if (card.find(input) != card.end())
			cout << card[input] << " ";
		else
			cout << "0 ";
	}
	return (0);
}