#include <stdio.h>
#include <algorithm>
using namespace std;

int n, arr[8];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);

    int max = 0;

    do {
        int now = 0;
        for (int i = 1; i < n; i++) {
            now += abs(arr[i - 1] - arr[i]);
        }
        if (now > max) max = now; 
    } while (next_permutation(arr, arr + n));

    printf("%d", max);
}