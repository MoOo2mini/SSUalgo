#include <bits/stdc++.h>
using namespace std;
int parse(void);  // 숫자 읽기.
string str;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int output;
    cin >> output;  // 첫번째 숫자 입력 받음.
    cin >> str;     // 나머지 문자열로 받음.

    while (!str.empty()) {
        string token;
        if (str[0] == '-') {  // '-'면 다음 '-'가 나오거나 문자열의 끝에 도달할 때까지 더함.
            int n = 0;
            do {
                str.erase(0, 1);
                n += parse();
            } while ((str[0] != '-') && !str.empty());  // '-'가 나오기 전까지 더함.
            output -= n;
        }

        else if (str[0] == '+') {  // '+'면 그냥 더함.
            str.erase(0, 1);       // '+' 삭제.
            output += parse();
        }
    }

    cout << output;
}

int parse(void) {  // 숫자 읽기.
    string token;
    int idx = 0, n;

    while (isdigit(str[idx])) {
        idx++;
    }
    token = str.substr(0, idx);  // '+'나 '-'의 앞까지 잘라서 문자열을 숫자로 변환.
    n = stoi(token);
    str.erase(0, idx);

    return n;
}