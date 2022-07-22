#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

bool find_pivot(int narr[], int pivot){
    int left, right, mid;
    left = 0;
    right = n - 1;
    
    while (left <= right){
        mid = (left + right) / 2;

        if (narr[mid] == pivot)   return true;
        if (narr[mid] > pivot) right = mid - 1;
        if (narr[mid] < pivot) left = mid + 1;
    }
    return false;
}

int main(){
    cin >> n;
    int narr[n];

    for (int i = 0; i < n; i++)
        cin >> narr[i];
    sort(narr, narr + n);

    cin >> m;
    int marr[m];

    for (int i = 0; i < m; i++)
        cin >> marr[i];

    for (int i = 0; i < m; i++)
        cout << find_pivot(narr, marr[i]) << " ";
}