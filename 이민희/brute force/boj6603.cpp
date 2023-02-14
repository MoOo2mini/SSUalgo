#include <iostream>
#include <vector>
using namespace std;

int k;
int arr[13];
int lotto[6];

void dfs(int cnt, int idx) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << lotto[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < k; i++) {
        lotto[cnt] = arr[i];
        dfs(cnt + 1, i + 1);
    }
}

int main() {
    while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		dfs(0, 0);
		cout << endl;
	}
}