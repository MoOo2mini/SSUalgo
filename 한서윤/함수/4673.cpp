<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int d(int m);
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	bool check[10005] = { false, };
	for (int i = 1; i < 10001; i++) {
		int num = d(i);
		if (num < 10001)
			check[num] = true;
	}
	for (int i = 1; i < 10001; i++) {
		if (check[i] == false)
			cout << i << "\n";
	}
}

int d(int n) {
	int result = n;
	while (n) {
		result += n % 10;
		n /= 10;
	}
	return result;
=======
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int d(int m);
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	bool check[10005] = { false, };
	for (int i = 1; i < 10001; i++) {
		int num = d(i);
		if (num < 10001)
			check[num] = true;
	}
	for (int i = 1; i < 10001; i++) {
		if (check[i] == false)
			cout << i << "\n";
	}
}

int d(int n) {
	int result = n;
	while (n) {
		result += n % 10;
		n /= 10;
	}
	return result;
>>>>>>> a1b14547949f07f921dadaba5468df309b7749d5
}