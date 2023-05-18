#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s, t;
    cin >> n;
    vector<pair<int, int> > v;
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        v.push_back(make_pair(s, t));
    }

    sort(v.begin(), v.end());

    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    pq.push(v[0].second);   //젤 첫수업의 끝나는 시간을 먼저 추가
    
    for(int i = 1; i < n; i++){
        if(v[i].first >= pq.top()){
            pq.pop();
            pq.push(v[i].second);
        }
        else pq.push(v[i].second);
    }
    cout << pq.size();
}