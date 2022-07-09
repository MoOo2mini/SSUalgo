#include <iostream>
using namespace std;

int a[10001];
int d[10001];

int findMax(int a, int b, int c)
{
    int max = a;
    if (max < b)
        max = b;
    if (max < c)
        max = c;
    return max;
}

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    d[1] = a[1];
    d[2] = a[1] + a[2];

    for (int i = 3; i <= n; i++)
        d[i] = findMax(d[i - 1], d[i-2] + a[i], a[i-1] + a[i] + d[i-3]);

    cout << d[n] << '\n';
}