#include <iostream>
#include <vector>
using namespace std;
// int map[50][50];
vector<pair<int, int> > house, chicken, pick;
int n, m;
int answer = 99999999;
bool visited[50];

int getDistance() {
    int sum = 0;
    int distance = 0;
    for (int i = 0; i < house.size(); i++) {
        int d = 99999999;
        int y = house[i].first;
        int x = house[i].second;
        for (int j = 0; j < pick.size(); j++) {
            int yy = pick[j].first;
            int xx = pick[j].second;
            distance = abs(y - yy) + abs(x - xx);
            
            d = min(d, distance);
        }
        sum += d;
    }
    return sum;
}

void dfs(int cnt, int idx) {
    if (cnt == m) {
        answer = min(answer, getDistance());
        // for (int i = 0; i < pick.size(); i++) {
        //     cout << pick[i].first << " " << pick[i].second << endl;
        // }
        // int tmp = getDistance();
        // if (tmp < answer) answer = tmp;
        // cout << tmp << endl;
        // cout << "------" << endl;
        return;
    }
    for (int i = idx; i < chicken.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        pick.push_back(chicken[i]);
        dfs(cnt + 1, i);
        pick.pop_back();
        visited[i] = false;
    }
}

int main() {
    int tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tmp;
            if (tmp == 1) {
                house.push_back(make_pair(i, j));
            } else if (tmp == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    dfs(0, 0);
    cout << answer;
}