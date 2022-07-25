// 부르트포스 알고리즘 무차별 대입
#include <iostream>
using namespace std;

int find_out(int n){
    int i = 666;
    int result = 0;
    string target;
    while (1){
        target = to_string(i);
        for (int j = 0; j < target.length() - 2; j++){
            if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6')
            {
                result++;
                if (result == n)
                    return i;
                break;
            }
        }
        i++;
    }
}

int main(){
    int n;
    cin >> n;

    cout << find_out(n);
}