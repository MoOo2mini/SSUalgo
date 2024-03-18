#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int k, sum = 0;
    vector<int> v;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        if (n == 0)
            v.pop_back();
        else
            v.push_back(n);
    }
    while (!v.empty()) {
        sum += v.back();
        v.pop_back();
    }
    cout << sum;
}