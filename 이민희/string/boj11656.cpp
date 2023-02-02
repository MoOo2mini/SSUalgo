#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string split(int i, string s) {
    string result = "";
    for (int j = i; s[j] != '\0'; j++) {
        result += s[j];
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    vector<string> v;
    for (int i = 0; s[i] != '\0'; i++) {
        v.push_back(split(i, s));
    }

    sort(v.begin(), v.end());

    for (int i = 0; s[i] != '\0'; i++) {
        cout << v[i] << endl;
    }
}