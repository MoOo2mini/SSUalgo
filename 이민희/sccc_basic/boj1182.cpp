#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
 
int main(int argc, char** argv) {
    int n, s, ans = 0;
    scanf("%d %d", &n, &s);
 
    vector<int> v(n);
    for (int i = 0; i < n; i++)scanf("%d", &v[i]);
 
    for (int i = 1; i < (1 << n); i++) {
        int sum = 0;
        for (int k = 0; k < n; k++) {
            if (i & (1 << k)) {
                sum += v[k];
            }
        }
        if (sum == s) ans++;
    }
 
    printf("%d\n", ans);
 
    return 0;
}