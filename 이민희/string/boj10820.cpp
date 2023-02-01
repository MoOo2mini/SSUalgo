#include <iostream>
using namespace std;

int main() {
    int small, large, space, num;
    string text;

    while (getline(cin, text)) {
        small = 0;
        large = 0;
        space = 0;
        num = 0;
        for (int i = 0; text[i] != 0; i++) {
            if (text[i] <= 'z' && text[i] >= 'a') {
                small++;
            } else if (text[i] <= 'Z' && text[i] >= 'A') {
                large++;
            } else if (text[i] <= '9' && text[i] >= '0') {
                num++;
            } else if (text[i] == ' ') {
                space++;
            }
        }

        cout << small << ' ' << large  << ' ' << num  << ' ' << space << '\n';
    }
}