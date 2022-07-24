// -27 gold5

#include <iostream>
using namespace std;

int k, n;
int arr[11];

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int result = 0;
    n--; // 인덱스라서
    while (arr[n]){
        result += k / arr[n];
        k %= arr[n];
        if (k == 0)
            break;
        n--;
    }
    cout << result;
}