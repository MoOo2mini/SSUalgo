#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;
	string str1, str2;
	str1.append(n1);
	str1.append(n2);
	str2.append(n3);
	str2.append(n4);
	cout << stoll(str1) + stoll(str2);
}