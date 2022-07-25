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
    int tmp;
    for (tmp = 0; tmp < n; tmp++){
        cin >> arr[tmp];
    }

    sort(arr, arr + tmp, greater<int>());

    int greater = 0;
    int i = tmp - 1;
    while(i >= 0){
        if (arr[i] > 0 && arr[i - 1] > 0)
            greater += arr[i] * arr[i - 1];
        else if (i - 1 < 0)
            greater += arr[i];
        else
            greater += arr[i] + arr[i - 1];
        i -= 2;
    }

    int less = 0;
    while(tmp){
        if (arr[i] > 0 && arr[i - 1] > 0)
            greater += arr[i] * arr[i - 1];
        else if (i - 1 < 0)
            greater += arr[i];
        else
            greater += arr[i] + arr[i - 1];
        i -= 2;
    }

    cout << greater;
}