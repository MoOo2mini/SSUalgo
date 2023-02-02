#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] <= 'z' && s[i] >= 'a') {
            int tmp = s[i] + 13;
            if (!(tmp <= 'z' && tmp >= 'a')) {
                s[i] -= 13;
            } else {
                s[i] = tmp;
            }
        } else if (s[i] <= 'Z' && s[i] >= 'A') {
            int tmp = s[i] + 13;
            if (!(tmp <= 'Z' && tmp >= 'A')) {
                s[i] -= 13;
            } else {
                s[i] = tmp;
            }
        }
    } 

    for (int i = 0; s[i] != '\0'; i++) {
        cout << s[i];
    }
}