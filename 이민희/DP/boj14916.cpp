#include <iostream>
using namespace std;

#define MAX 100000

int main() {
    int d[] = {5, 2};
    int n;
    cin >> n;
    int c[n + 1];
    for (int i = 1; i <= n; i++) {
        c[i] = MAX;
    }

    c[0] = 0;

    for (int j = 1; j <= n; j++){
        for (int i = 0; i < 2; i++) {
            if ((d[i] <= j) && (c[j - d[i]] + 1 < c[j])) {
                c[j] = c[j - d[i]] + 1;
            } 
        }
    }

    if (c[n] == MAX){
        cout << -1;
        return 0;
    }
    cout << c[n];
}