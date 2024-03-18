#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    while (1) {
        string str;
        int i = 0;
        vector<char> v;
        bool check = true;
        getline(cin, str);
        if (str == ".") break;
        while (str[i] != '.') {
            if (str[i] == '(' || str[i] == '[') {
                v.push_back(str[i]);
            } else if (str[i] == ')') {
                if (!v.empty() && v.back() == '(')
                    v.pop_back();
                else {
                    check = false;
                    break;
                }
            } else if (str[i] == ']') {
                if (!v.empty() && v.back() == '[')
                    v.pop_back();
                else {
                    check = false;
                    break;
                }
            }
            i++;
        }
        if (check && v.empty())
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}