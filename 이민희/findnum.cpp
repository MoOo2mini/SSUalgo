#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int num;
int dest[100000];

int findnums(int target)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (dest[mid] == target)
            return 1;
        else if (dest[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> dest[i];
    }
    sort(dest, dest + n);
    
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> num;
        cout << findnums(num) << "\n"; // endl의 경우 버퍼를 flush 하기 때문에 속도를 늦춘다.
        // 따라서 endl -> "\n" 하는 것이 좋다.
    }
}