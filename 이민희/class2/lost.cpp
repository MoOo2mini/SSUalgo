#include <iostream>
#include <string>
using namespace std;
// - 뒤에 오는 모든 숫자들은 음수가 되어 빼준다는 아이디어를 떠올리지 못함.
// 구현 전 최적화에 대한 고민을 더 많이 해야함.
 
int main() {
    string input;
    cin >> input;
 
    int result = 0;
    string num;
    bool isMinus = false;
 
    for (int i = 0; i <= input.size(); i++) {
        
        if (input[i] == '-' || input[i] == '+' || i==input.size()) {
            if (isMinus) {
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
        }
        else {
            num += input[i];
        }
 
        if (input[i] == '-') {
            isMinus = true;
        }    
    }
    
    cout << result;
}

