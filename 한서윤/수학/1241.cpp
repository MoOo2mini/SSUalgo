// 하나하나 확인하면 시간초과.
// 배열에 각 숫자의 개수를 저장하고, 머리의 약수면 그 수들을 더함.

#include <bits/stdc++.h>
using namespace std;
int num[1000001];

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
        num[input]++;
    }

    for (int i = 0; i < n; i++) {
        int count = -1;
        for (int j = 1; j * j <= v[i]; j++) {
            if (!(v[i] % j)) {  // 약수의 개수를 더함.
                count += num[j];
                if (j != (v[i] / j))  // 제곱수가 아니면 더함.
                    count += num[v[i] / j];
            }
        }
        cout << count << '\n';
    }
}