#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n;
    int cnt = 1;
	cin >> n;
	vector<pair<int, int> > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a.begin(), a.end()); // 끝나는 시간을 우선적으로 정렬한다.

	int end=a[0].first; //최초로 끝나는 회의를 end에 저장해줍시다
    for(int i=1;i<n;i++){
        if(end<=a[i].second){ //second는 현재 탐색중인 회의 시작시간인데 가장 먼저
        			//조건이 참이 될 때가 가장 텀이 짧을 때 입니다.
            cnt++;
            end=a[i].first;
        }
    }
    cout << cnt;
}