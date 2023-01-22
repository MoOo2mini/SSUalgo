#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countChange(string str) {
    int change = 0;

    for (int i = 1; i < (int) str.length(); i++) {
        if (str[i - 1] != str[i]) change++;
    }
    
    return change;
}

int main() {
    int n;
    cin >> n;

    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min = 10000;
    do {
        string str = "";
        for (int i = 0; i < n; i++) str += arr[i];
        int change = countChange(str);
        if (change < min) min = change;
    } while (next_permutation(arr, arr + n));

    cout << min;
}