#include <iostream>
using namespace std;
string arr[100];
int n;

string decode(string s, int num) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] + num >= 'z') {
            result += (char)(s[i] + num - 'z' + 'a');
        } else {
            result += s[i] + num + 1;
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i <= 'z' - 'a'; i++){
        string decoded = decode(s, i);
        for (int j = 0; j < n; j++) {
            if (decoded.find(arr[j]) != string::npos) {
                cout << decoded;
                return 0;
            }
        }
    }
}