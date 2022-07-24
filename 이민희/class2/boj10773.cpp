#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> s;

int main(){
    int tmp;

    cin >> n;
    while (n--){
        cin >> tmp;
        if (tmp != 0)
            s.push(tmp);
        else {
            if (!s.empty()) {
                s.pop();
            }
        }
    }
    int result = 0;
    while (!s.empty()){
        result += s.top();
        s.pop();
    }

    cout << result;
}