#include <iostream>
using namespace std;

int main(){
    int tmp, result;
    result = 0;
    for (int i = 0; i < 5; i++){
        cin >> tmp;
        result += tmp * tmp;
    }

    result %= 10;

    cout << result;
}