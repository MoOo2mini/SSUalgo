#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
		return (a < b);
	return (a.length() < b.length());
}

int main(void)
{
	int n;
	string s;
	vector<string> arr;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (find(arr.begin(), arr.end(), s) == arr.end())	//새 단어인 경우
			arr.push_back(s);
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << "\n";
	return (0);
}