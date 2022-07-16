#include <iostream>
using namespace std;

unsigned int ans;
int k, n;
unsigned int arr[10001];

int main(){

    unsigned int max_value = 0;

    cin >> k >> n;

    for (int i = 0; i < k; i++){
        cin >> arr[i];
        max_value = max(max_value, arr[i]);
    }

    unsigned int left = 1;
    unsigned int right = max_value;
    unsigned int mid;

    // 결과값은 1~최대입력값 사이에 있다.
    while (left <= right)
    {
        mid = (left + right) / 2;

        // 몫의 합을 저장하는 변수
		unsigned int now = 0; 
        
		for (int i = 0; i < k; i++)
		{
			//mid로 나눈 몫을 저장
			now += arr[i] / mid;
		}

		if (now >= n)
		{
			// 현재 mid로 나눈 값이 N보다 크거나 같다면,
			// left를 움직여 길이가 더 긴 경우는 가능한지 검사
			left = mid + 1;
            
			// N개를 만들 수 있을 때, 답을 더 큰 값으로 계속 갱신
			ans = max(ans, mid);
		}
		else
		{
			// 현재 mid로 나눈 값이 N보다 작다면,
			// right 움직여 길이가 더 짧은 경우는 가능한지 검사
			right = mid - 1;
		}
	}
	cout << ans << '\n';
}