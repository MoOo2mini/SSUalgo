#include <iostream>
#include <vector>
using namespace std;

int maxDay;

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

int LCM(int a, int b) {
	return (a * b) / GCD(a, b);
}

int countDays(int N, int M, int x, int y) {
    if (x == y && x <= N && y <= M) return x;
    long answer = x;
    int month = x; int day = x;
    if (day > M) {
        if (day % M != 0) {
            day %= M;
        } else {
            day = M;
        }
    } else {
        day = x;
    }
    // cout << "init day : " << day << endl;
    while (day != y) {
        day += N;
        if (day % M != 0) {
            day %= M;
        } else {
            day = M;
        }
        answer += N;
        // cout << "day : " << day << endl;
        if (answer > maxDay) {
            return -1;
        }
    }
    return answer;
}

int main() {
    int T;
    int N, M, x, y;
    vector<long> v;
    long answer;
    int month, day;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M >> x >> y;
        maxDay = LCM(N, M);
        answer = countDays(N, M, x, y);
        v.push_back(answer);
    }

    for (int i = 0; i < T; i++) {
        cout << v[i] << endl;
    }
}