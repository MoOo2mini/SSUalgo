#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string str;
	cin >> str;
	int n[26] = { 0, }, max = 0, check = 0, idx;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < 'a') n[str[i] - 'A']++;
		else n[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (n[i] > max) {
			max = n[i];
			check = 0;
			idx = i;
		}
		else if (n[i] == max) check++;
	}
	if (check) cout << '?';
	else cout << (char)(idx + 'A');
}