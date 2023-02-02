#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  cin.tie(NULL);

    int n, c;
    cin >> n >> c;
    int tmp;
    vector<long long> arr;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    cout << arr[c - 1];
}