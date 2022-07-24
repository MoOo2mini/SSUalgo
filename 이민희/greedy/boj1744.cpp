#include <iostream>
#include <algorithm>
using namespace std;

int arr[51];
int n;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n;
    int i;
    for (i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + i, greater<int>());

    int result = 0;
    i--;
    while(i >= 0){
        if (arr[i] > 0 && arr[i - 1] > 0)
            result += arr[i] * arr[i - 1];
        else if (i - 1 < 0)
            result += arr[i];
        else
            result += arr[i] + arr[i - 1];
        i -= 2;
    }

    cout << result;
}