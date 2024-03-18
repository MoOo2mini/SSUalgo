#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, num[1000], temp;
	cin >> n;

	
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		num.push_back(num[i]);
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (num[i] < num[j]) {
				num.insert(num.begin() + j, num[i]);
				num.erase(num.begin() + i + 1);
				break;
			}
		}
	}


	/* °Á ÀÌ·¸°Ô ÇØµµ µÆÀ»µí ?
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		temp = num[i];
		for (int j = 0; j < i; j++) {
			if (num[i] < num[j]) {
				for (int k = j; k <= i; k++) num[k + 1] = num[k];
				num[j] = temp;
				break;
			}
		}
	}
	*/

	for (int i = 0; i < n; i++) cout << num[i] << '\n';
}