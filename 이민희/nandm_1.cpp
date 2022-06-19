#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = {0,};
bool visited[MAX] = {0,};

void print()
{
    for(int i = 0; i < m; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return;
}

void dfs(int count){
    
    if (count == m)
        print();
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[count] = i + 1;
            dfs(count + 1);
            visited[i] = false;
        }   
    }
}

int main()
{
    cin >> n >> m;
    dfs(0);
    return 0;
}
