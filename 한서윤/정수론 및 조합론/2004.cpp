#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	long long n, m, cnt2 = 0, cnt5 = 0, cnt = 0; // nÀ» 5ÀÇ °ÅµìÁ¦°öÀ¸·Î ³ª´«°É ´õÇØ¼­ ±¸ÇÔ
	cin >> n >> m;
	for (long long i = 2; i <= n; i *= 2)
		cnt2 += n / i;
	for (long long i = 2; i <= n - m; i *= 2)
		cnt2 -= (n - m) / i;
	for (long long i = 2; i <= m; i *= 2)
		cnt2 -= m / i;

	for (long long i = 5; i <= n; i *= 5)
		cnt5 += n / i;
	for (long long i = 5; i <= n - m; i *= 5)
		cnt5 -= (n - m) / i;
	for (long long i = 5; i <= m; i *= 5)
		cnt5 -= m / i;
	cnt2 > cnt5 ? cnt = cnt5 : cnt = cnt2;
	cout << cnt;
}