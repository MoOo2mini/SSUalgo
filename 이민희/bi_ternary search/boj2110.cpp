// 입력이 10억이나 나온다? -> 웬만하면 이분 탐색
// 범위는 힌트가 될 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 공유기 위치 저장용 Vector
vector<int> router;

// 최대 간격을 가지는 공유기 위치 찾기
int find_max_dist(int n, int c){

    // 기준 간격 이분 탐색을 위한 변수
    int l_dist = 0;                     // 첫 번째 공유기에서 첫 번째 공유기까지의 간격
    int r_dist = router[n-1]-1;         // 첫 번째 공유기에서 마지막 공유기까지의 간격

    // 결과 간격
    int result_dist;

    // 이분법을 사용해, 모든 간격 탐색이 끝날때까지 진행
    while(l_dist<=r_dist){

        // 설치한 공유기 개수 (첫 번째 공유기는 설치하고 시작)
        int install_router = 1;

        // 기준 간격 갱신
        int mid_dist = (l_dist+r_dist)/2;   

        // 첫 번째 공유기 위치
        int start = router[0];

        // 각 공유기의 간격 확인
        for (int i=1; i<n; ++i){

            // 간격 확인할 공유기 위치
            int end = router[i];

            // 공유기 간격이 기준 간격을 넘는지 확인한 뒤, 넘는 간격에는 공유기를 설치하고
            // 해당 위치를 다시 탐색 시작 위치로 변경
            if (end - start >= mid_dist){
                install_router += 1;
                start = end;
            }
        }

        // 공유기 간격 탐색이 끝난 뒤, 설치한 공유기 개수가 C개 이상이라면,
        if (install_router >= c){
            // 공유기 설치에 사용된 간격을 결과 간격으로 임시 저장
            result_dist = mid_dist;
            // 이분법을 사용한 간격 갱신 시, 이전보다 넓은 간격을 사용하기 위해, L 수정
            l_dist = mid_dist + 1;
        }
        // 설치한 공유기 개수가 C개 미만이라면,
        else{
            // 이분법을 사용한 간격 갱신 시, 이전보다 좁은 간격을 사용하기 위해, R 수정
            r_dist = mid_dist - 1;
        }
    }

    // 결과 거리 반환
    return result_dist;

}

int main(){

    // 공유기 개수, 설치 개수
    int n, c;
    cin >> n >> c;

    // 공유기 위치 입력
    int loc;
    for (int i=0; i<n; ++i){
        cin >> loc;
        router.push_back(loc);
    }

    // 공유기 위치 정렬
    sort(router.begin(), router.end());

    // 공유기 간 최대 거리 탐색 함수 실행
    cout << find_max_dist(n, c);

}