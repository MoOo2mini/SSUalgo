#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> v, sv;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sv = v;
	sort(sv.begin(), sv.end());
	sv.erase(unique(sv.begin(), sv.end()), sv.end());
	for (int i = 0; i < n; i++) // 중첩 반복문 했더니 시간초과나서 이분탐색으로 . . .
		cout << lower_bound(sv.begin(), sv.end(), v[i]) - sv.begin() << " ";
		// iterator 반환하므로 시작 주소 빼면 인덱스 구할 수 있음
}