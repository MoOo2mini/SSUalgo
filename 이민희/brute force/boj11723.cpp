#include <iostream>
using namespace std;

bool arr[21];

int main() {
    int t, n;
    string s = "";
    cin >> t;
    while (t--) {
        cin >> s >> n;
        if (s == "add") {
            arr[n] = true;
        }
        if (s == "remove") {
            arr[n] = false;
        }
        if (s == "check") {
            if (arr[n]) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
        if (s == "toggle") {
            if (arr[n]) {
                arr[n] = false;
            } else {
                arr[n] = true;
            }
        }
        if (s == "all") {
            for(int k = 1; k<=20; k++){ arr[k] = 1;}
        }
        if (s == "empty") {
            for(int k = 1; k<=20; k++){ arr[k] = 0;}
        }
    }
}