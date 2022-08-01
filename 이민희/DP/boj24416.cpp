#include <iostream>
using namespace std;

#define MAX 41

int recursive[MAX];

int main(){
    int n;
    
    cin >> n;
    recursive[1] = 1;
    recursive[2] = 1;
    recursive[3] = 2;
    if (n <= 3) {
        cout << recursive[n] << " 1";
        return 0;
    }
    for (int i = 4; i <= n; i++){
        recursive[i] = recursive[i - 1] + recursive[i - 2];
    }
    cout << recursive[n] << " " << n - 2;
}