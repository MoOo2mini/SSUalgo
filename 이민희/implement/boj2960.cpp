#include <iostream>
#include <vector>
using namespace std;
bool visited[1000];
int main() {
    int n, k;
    cin >> n >> k;

    int cnt = 0;

    int index = 2;
    while (index <= n) {
        int p = index;
        if (visited[p] == 0){
            visited[p] = 1;
            cnt++;
        }
        if (cnt == k) {
            cout << p;
            return 0;
        }
        int i = 1;
        int tmp = p;
        while (p <= n) {
            p += tmp;
            if (visited[p] == 0 && p <= n) {
                cnt++;
                visited[p] = 1;
                if (cnt == k) {
                    cout << p;
                    return 0;
                }
            }
            i++;
        }

        index++;
    }
}