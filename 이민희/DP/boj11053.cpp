#include <iostream>
using namespace std;

int num[1001];

int main()
{
    int n, count, flag;

    count = 1;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> num[i];
    
    flag = num[0];
    for (int i = 0; i < n; i++)
    {
        if (num[i] > flag)
            count++;
        flag = num[i];
    }
    cout << count << '\n';
}