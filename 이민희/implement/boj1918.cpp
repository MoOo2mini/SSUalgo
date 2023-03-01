#include <iostream>
#include <vector>
using namespace std;
string s;
vector<char> stack;

int checkIsp(char c) {
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 3;
    }
    if (c == '(') {
        return 8;
    }
    return 0;
}

int checkIcp(char c) {
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 3;
    }
    if (c == '(') {
        return 0;
    }
    return 0;
}

void checkLetter(char c) {
    if (stack.empty()) {
        stack.push_back(c);
        return;
    }
    if (c == ')') {
        char tmp;
        while (true) {
            tmp = stack.back();
            if (stack.back() != '(') cout << stack.back();
            stack.pop_back();
            if (tmp == '(') {
                return;
            } 
        }
    }
    int isp = checkIsp(stack.back());
    int icp = checkIcp(c);
    if (isp <= icp) {
        // if (stack.back() != '(') cout << stack.back();
        // stack.pop_back();
        while (!stack.empty() && top) {
            if (stack.back() != '(') cout << stack.back();
            stack.pop_back(); 
        }
        stack.push_back(c);
    } else {
        stack.push_back(c);
    }

    return;
}

int main() {
    cin >> s;
    if (!stack.empty()) cout << stack.front();
    for (int i = 0; i < s.length(); i++) {
        if (s[i] <= 'Z' && s[i] >= 'A') {
            cout << s[i];
        } else {
            checkLetter(s[i]);
        }
    }
    if (!stack.empty()) {
        while (!stack.empty()) {
            if (stack.back() != '(') cout << stack.back();
            stack.pop_back(); 
        }
    }
}