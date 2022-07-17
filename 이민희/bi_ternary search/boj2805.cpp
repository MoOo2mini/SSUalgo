#include <iostream>
using namespace std;

long long ans;
long long n, m;
// 나무의 최대길이가 10억이기 때문에 넉넉하게 longlong 자료형으로 만들어 주었다.
// 이것땜에 삽질했다.^^..

int main(){

    long long max_value = 0;

    cin >> n >> m;

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        max_value = max(arr[i], max_value);
    }

    long long left = 1;
    long long right = max_value;
    long long mid;

    // 결과값은 1~최대입력값 사이에 있다.
    while (left <= right)
    {
        mid = (left + right) / 2;

        // 몫의 합을 저장하는 변수
		long long now = 0; 
        long long tmp;
        
		for (int i = 0; i < n; i++)
		{
			tmp = arr[i] - mid;
            if (tmp > 0)
                now += tmp;
		}

		if (now >= m)
		{
			// 현재 mid로 나눈 값이 N보다 크거나 같다면,
			// left를 움직여 길이가 더 긴 경우는 가능한지 검사
			left = mid + 1;
            
			// N개를 만들 수 있을 때, 답을 더 큰 값으로 계속 갱신
			ans = max(ans, mid);
		}
		else if (now < m)
		{
			right = mid - 1;
		}
	}
	cout << ans << '\n';
}