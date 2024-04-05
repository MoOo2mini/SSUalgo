#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int length, carry = 0, sum;
	string num1, num2, result;
	cin >> num1 >> num2;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	if (num1.length() > num2.length()) length = num1.length();
	else length = num2.length();
	for (int i = 0; i < length; i++) {
		if (num1[i]=='\0') num1.push_back('0');
		if (num2[i]=='\0') num2.push_back('0');
		sum = (num1[i] - '0') + (num2[i] - '0') + carry;
		if (sum >= 10) {
			carry = 1;
			sum -= 10;
		}
		else carry = 0;
		result.push_back(sum + '0');
	}
	if (carry == 1) result.push_back('1');
	reverse(result.begin(), result.end());
	cout << result;
}