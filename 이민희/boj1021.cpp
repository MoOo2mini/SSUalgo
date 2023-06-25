#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
using namespace std;
 
int main(int argc, char *argv[])
{
	int n;
	int find;
	int num;
	int index;
	int count = 0;
	deque<int> d;
 
	cin >> n;
	cin >> find;
 
	for (int i = 1; i <= n; ++i) {
		d.push_back(i);
	} // n이라면 1, 2, 3, ... , n - 1, n을 생성
 
	while (find--){
		cin >> num;
 
		for (int i = 0; i < d.size(); ++i) {
			if (d[i] == num) {
				index = i; // 찾으려는 수의 인덱스를 저장
				break;
			}
		}
 
		if (index < d.size() - index) { // 찾으려는 수가 앞쪽에 있는지, 뒤쪽에 있는지
			while (1) {
				if (d.front() == num) { // 맨앞의 수가 같다면 pop으로 빼고 반복문 탈출
					d.pop_front();
					break;
				}
				++count;
				d.push_back(d.front()); // 아니라면 앞에 있는 수를 뒤로 보내버림.
				d.pop_front();
			}
		}
		else {
			while (1) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				++count;
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
	cout << count << endl;
	
	return 0;
}