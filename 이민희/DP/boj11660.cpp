#include <iostream>

using namespace std;

int arr[1025][1025];
int ans[1025][1025];
int n, m;
int x1, y1, x2, y2;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int r = 1 ; r <= n ; r++)
    {
        for(int c = 1 ; c <= n ; c++)
        {
            cin >> arr[r][c];
            ans[r][c] = ans[r][c-1] + arr[r][c];       // 각 위치의 누적합은 해당 행만의 누적합이 된다
        }
    }
    for(int i = 0 ; i < m ; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int answer = 0;
        for(int r = x1 ; r <= x2 ; r++)                 // 입력 받은 범위의 행들의 누적합을 더해준다
        {
            answer += ans[r][y2] - ans[r][y1-1];        // y2 위치의 누적합 - y1 위치의 누적합
        }

        cout << answer << '\n';
    }
}