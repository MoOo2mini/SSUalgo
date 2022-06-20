#include <iostream>
#define MAX 100000
using namespace std;


int n, m;
int *dest;

int findnums(int target)
{
    int low = 0;
    int high = m - 1;
    int mid = m / 2 + 1;

    while(low <= high) {
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

void quickSort(int *dest, int left, int right)
{
    if(left >= right){
        // 원소가 1개인 경우
        return; 
    }
    
    int pivot = left;
    int i = pivot + 1; // 왼쪽 출발 지점 
    int j = right; // 오른쪽 출발 지점
    int temp;
    
    while(i <= j){
        // 포인터가 엇갈릴때까지 반복
        while(i <= right && dest[i] <= dest[pivot]){
            i++;
        }
        while(j > left && dest[j] >= dest[pivot]){
            j--;
        }
        
        if(i > j){
            // 엇갈림
            temp = dest[j];
            dest[j] = dest[pivot];
            dest[pivot] = temp;
        }else{
            // i번째와 j번째를 스왑
            temp = dest[i];
            dest[i] = dest[j];
            dest[j] = temp;
        }
    } 
    
    // 분할 계산
    quickSort(dest, left, j - 1);
    quickSort(dest, j + 1, right);
}

int main()
{
    cin >> n;
    dest = new int(n);
    for (int i=0; i<n; i++)
        cin >> *(dest + i);
    
    quickSort(dest, 0, n - 1);
    
    cin >> m;
    int *src = new int(m);
    for (int i=0; i<m; i++)
        cin >> *(src + i);
    
    for (int i=0; i<m; i++)
        cout << findnums(*(src + i)) << endl;
}