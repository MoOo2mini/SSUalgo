#include <iostream>
using namespace std;
const int MAX = 1000001;
long long arr[MAX];

int main() {
    int t, n;
    cin >> t;
    
    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; i * j <= MAX; j++) {
            arr[i * j] += i;
        }
        arr[i] += arr[i - 1];
    }

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << arr[n] << endl;
    }
    
}