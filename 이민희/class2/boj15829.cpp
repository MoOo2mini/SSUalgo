#include <iostream>
using namespace std;

int main(){
    int len;
    char s[51];
    cin >> len;
    cin >> s;

    int i = 0;
    unsigned long long base = 1;
    unsigned long long result = 0;
    while (len--){
        result += base * (s[i] - 'a' + 1);
        base *= 31;
        result %= 1234567891;
        base %= 1234567891;
        i++;
    }

    cout << result;
}