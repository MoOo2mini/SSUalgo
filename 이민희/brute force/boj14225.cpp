#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> v;
bool arr[2000000];
bool visited[20];
int result[20];
int n, m;

void dfs(int cnt, int idx) {
    if (cnt == m) {
        int tmp = 0;
        for (int i = 0; i < m; i++) {
            tmp += result[i];
        }
        arr[tmp] = true;
    }
    for (int i = idx; i < n; i++) {
        if (visited[i]) continue;
        if (cnt - 1 >= 0 && result[cnt - 1] > v[i]) continue;

        visited[i] = true;
        result[cnt] = v[i];
        dfs(cnt + 1, idx + 1);
        result[cnt] = 0;
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= n; i++) {
        m = i;
        dfs(0, 0);
    }

    int i = 1;
    while (true) {
        if (!arr[i]) {
            cout << i;
            break;
        }
        i++;
    }
}

/**
 * @file boj14225.cpp
 * 시간 초과 하지 않는 코드 
 *
 * #include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int N;
int check[2000001];
int seq[21];

void solve(int x, int sum)
{
	check[sum] = true;
	if (x == N) return;
	else{
		solve(x + 1, sum); // 현재 인덱스를 sum에 포함 시킴.
		solve(x + 1, sum + seq[x]); // 포함 시키지 않음.
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> seq[i];
	
	solve(0, 0);

	int j = 1;
	while (check[j] == true) j++;
	cout << j;
}
 * 
 */