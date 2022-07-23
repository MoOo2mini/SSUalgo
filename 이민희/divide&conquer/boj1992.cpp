#include <iostream>
#include <string>
using namespace std;
const int MAX = 65; //3^7

int N;
string arr[MAX];

void func(int n, int y, int x)

{
    if (n == 1){
        cout << arr[y][x];
        return;
    }

    bool zero = true, plus = true;

    for(int i = y; i< y+n; i++){
        for(int j = x; j< x+n; j++){
            if (arr[i][j] == '0'){
                plus = false;
            }
            if (arr[i][j] == '1'){
                zero = false;
            }
        }
    }

    if (zero) 
        cout << '0';
    else if (plus)
        cout << '1';
    else{
        cout << '(';
        int div = n / 2;
        func(div, y, x);
        func(div, y, x + div);
        func(div, y + div, x);
        func(div, y + div, x + div);
        cout << ')';
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    func(N, 0, 0);
    return 0;
}
