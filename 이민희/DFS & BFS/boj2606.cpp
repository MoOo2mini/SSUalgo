#include <iostream>
#include <queue>
using namespace std;

bool arr[101];
vector<int> v[101];

int main(){
    int from, to;
    int com;
    int pairs;


    cin >> com >> pairs;

    for (int i = 0; i < pairs; i++)
    {
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    int result = 0;
    queue<int> q;
    q.push(1);

    arr[1] = true;

    while (!q.empty()){
        int w = q.front();
		q.pop();
		for (int i = 0; i < v[w].size(); i++) {
			int y = v[w][i];
			if (!arr[y]) {
				q.push(y);
                result++;
				arr[y] = true;
			}
		}
    }

    cout << result;
}