#include <iostream>
using namespace std;

int arr[1001];

int main()
{
    int n;
    cin >> n;

    int dp[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    int sum = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }

            sum = max(sum, dp[i]);
        }
    }
    
    cout << sum;
}