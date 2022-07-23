#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a_index, b_index;

int main(){
    // 2개의 배열이 이미 정렬 되어있음을 생각해야한다.
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    // 위 세줄은 c 스트림과 cpp 스트림의 동기화를 끊어 속도를 향상시키는 코드이다.

    cin >> n >> m;
    int a[n];
    int b[m];

    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<m;i++) {
        cin >> b[i];
    }

    while(a_index < n && b_index < m) {
        if(a[a_index]<=b[b_index]) {
            cout << a[a_index++] << " ";
        } else {
            cout << b[b_index++] << " ";
        }
    }
    while(a_index<n) {
        cout << a[a_index++] << " ";
    }
    while(b_index<m) {
        cout << b[b_index++] << " ";
    }
}