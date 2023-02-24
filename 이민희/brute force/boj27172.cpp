#include <iostream>
#define MAX 1000001

using namespace std;

int n;
int score[MAX];
int card[MAX];
int player[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        player[i] = a;
        card[a] = 1;
    }
    
    for (int i = 1; i <= MAX; i++)
    {
        if (!card[i])
            continue;
        for (int j = i * 2; j <= MAX; j += i)
        {
            if (card[j])
            {
                score[j]--;
                score[i]++;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
        cout << score[player[i]] << " ";
    return 0;
}