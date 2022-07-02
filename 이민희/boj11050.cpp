#include <iostream>
using namespace std;

int main()
{
    int k, n;
    cin >> n; cin >> k;
    int div = n - k;

    if (k < 0)
        cout << "0\n";
    else if (k > n)
        cout << "0\n";
    else
    {
        int result = 1;
        while (n > k)
            result *= n--;
        cout << result << endl;
        while (div)
            result /= div--;

        cout << result << '\n';
    }
}