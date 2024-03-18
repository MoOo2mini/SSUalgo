#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
int GCD(int a, int b);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	vector<int> v, result;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end()); // 정렬 안 하면 빼기할 때 음수 나와서 에러
	int gcd = v[1] - v[0];
	for (int i = 2; i < n; i++) {
		int num = v[i] - v[i - 1];
		gcd = GCD(gcd, num);
	}
	for (int i = 1; i * i <= gcd; i++) { // 시간초과나서 중간까지 검사하고 나머지 넣는 방식으로 수정
		if (gcd % i == 0) {
			result.push_back(i);
			if (i * i != gcd) result.push_back(gcd / i);
		}
	}
	sort(result.begin(), result.end()); // 약수들 정렬
	for (int i = 1; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}

int GCD (int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	else return GCD(a % b, b);
}