#include <iostream>
using namespace std;

int n, m, k;

int main(){
    cin >> n >> m >> k;

    int result = 0;
    while (1){
        n -= 2;
        m -= 1;
        if (n + m < k)
            break;
        else if (n >= 0 && m >= 0)
            result++;
    }
    cout << result;
}