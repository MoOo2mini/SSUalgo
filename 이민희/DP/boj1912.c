#include <stdio.h>
#include <stdlib.h>
#define max(x,y) ((x > y) ? x : y)

int findmax(int *arr, int len)
{
    int max = arr[0];
    int i = 1;
    while (i < len)
    {
        if (max < arr[i])
            max = arr[i];
        i++;
    }
    return (max);
}

int main(void)
{
    int len;
    int max;
    int tmp;

    scanf("%d", &len);
    int dp[len];
    int arr[len];
    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    dp[0] = arr[0];
    for (int i = 1; i < len; i++)
        dp[i] = max(arr[i], arr[i] + dp[i - 1]);
    max = findmax(dp, len);
    printf("%d", max);
}