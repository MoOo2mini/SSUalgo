#include <iostream>
using namespace std;

void print(bool arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i])
            cout << i + 1;
    }
}

void nandm(bool arr[], int n, int m, int count){
    
    if (count == m)
        print(arr, n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == false)
            arr[i] = true;
        nandm(arr, n, m, count + 1);
        arr[i] = false;
    }
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    bool arr[n];
    for (int i = 0; i < n; m++)
        arr[i] = false;
    
    nandm(arr, n, m, 0);
    return 0;
}