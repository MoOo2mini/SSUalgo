#include <iostream>
using namespace std;

int n, m;
int arr[10];

void dfs(int ctn) {
    if (ctn == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return ;
    } else {
        for (int i = 1; i <= n; i++) {
            if (ctn > 0) {
                if (i < arr[ctn - 1]) {
                    continue;
                }
            }
            arr[ctn] = i;
            dfs(ctn + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(0);
}