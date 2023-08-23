#include <iostream>
#include <list>
using namespace std;

int main() {
    list<char> v;
    auto v_idx = v.begin();  // v가 비어있을 경우에도 v_idx를 초기화할 수 있도록 수정
    int n;
    string s;
    cin >> n;
    while (n--) {
        v.clear();
        v_idx = v.begin();
        cin >> s;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '<') {
                if (v.begin() != v_idx) {
                    v_idx--;
                }
            } else if (s[i] == '>') {
                if (v.end() != v_idx) {
                    v_idx++;
                }
            } else if (s[i] == '-') {
                if (v_idx != v.begin()) {
                    v_idx = v.erase(--v_idx);
                }
            } else {
                v.insert(v_idx, s[i]);
            }
        }
        for (v_idx = v.begin(); v_idx != v.end(); v_idx++) cout << *v_idx;
        cout << '\n';
    }
}