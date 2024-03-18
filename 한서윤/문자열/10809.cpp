#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string str;
	cin >> str;
	int check[26];
	fill_n(check, 26, -1);
	for (int i = 0; i < str.length(); i++) {
		if (check[str[i] - 'a'] == -1)
			check[str[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << check[i] << " ";
}