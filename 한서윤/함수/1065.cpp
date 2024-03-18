<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, cnt = 0, t1, t2, t3;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i / 100 == 0) cnt++;
		else {
			t1 = i / 100;
			t2 = i / 10 % 10;
			t3 = i % 10;
			if (t1 - t2 == t2 - t3) cnt++;
		}
	}
	cout << cnt;
=======
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, cnt = 0, t1, t2, t3;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i / 100 == 0) cnt++;
		else {
			t1 = i / 100;
			t2 = i / 10 % 10;
			t3 = i % 10;
			if (t1 - t2 == t2 - t3) cnt++;
		}
	}
	cout << cnt;
>>>>>>> a1b14547949f07f921dadaba5468df309b7749d5
}