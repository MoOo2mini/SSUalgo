#include<iostream>
#include<vector>
#include<cmath>
 
#define endl "\n"
#define MAX 100010
using namespace std;
 
int N, M;
int Arr[MAX];
int Sum[MAX];
vector<pair<int, int>> Cmd;
 
void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> Arr[i];
        Sum[i] = Sum[i - 1] + Arr[i];
    }
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        Cmd.push_back(make_pair(a, b));
    }
}
 
void Solution()
{
    for (int i = 0; i < M; i++)
    {
        int Start = Cmd[i].first;
        int End = Cmd[i].second;
 
        cout << Sum[End] - Sum[Start - 1] << endl;
    }
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Solve();
 
    return 0;
}
