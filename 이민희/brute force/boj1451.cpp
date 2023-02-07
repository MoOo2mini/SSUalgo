#include <iostream>
#include <vector>
#include <algorithm> 
#include <stdio.h>
using namespace std;
int m, n;
int arr[50][50];

int getArea(int startx, int starty, int endx, int endy) {
    int result = 0;
    for (int i = starty; i < endy; i++) {
        for (int j = startx; j < endx; j++) {
            result += arr[i][j];
        }
    }

    return result;
}

int main() {
    cin >> m >> n;
    vector<long long> max;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
            //%1d를 쓰면 입력받은 정수도 문자 단위로 나누어서 처리가 가능
        }
    }

    //1번 모양으로 자르기
    long long max1 = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = i; j < m; j++) {
            long long top = getArea(0, 0, n, i);
            long long mid = getArea(0, i, n, j);
            long long bot = getArea(0, j, n, m);

            if (max1 < top * mid * bot) {
                max1 = top * mid * bot;
            }
        }
    }

    long long max2 = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = i; j < m; j++) {
            long long top = getArea(0, 0, i, m);
            long long mid = getArea(i, 0, j, m);
            long long bot = getArea(j, 0, n, m);

            if (max2 < top * mid * bot) {
                max2 = top * mid * bot;
            }
        }
    }

    long long max3 = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            long long top = getArea(0, 0, j, i);
            long long mid = getArea(0, i, j, m);
            long long bot = getArea(j, 0, n, m);

            if (max3 < top * mid * bot) {
                max3 = top * mid * bot;
            }
        }
    }

    long long max4 = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            long long top = getArea(0, 0, n, j);
            long long mid = getArea(j, 0, n, i);
            long long bot = getArea(j, i, n, m);

            if (max4 < top * mid * bot) {
                max4 = top * mid * bot;
            }
        }
    }

    long long max5 = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            long long top = getArea(0, 0, n, i);
            long long mid = getArea(0, i, j, m);
            long long bot = getArea(j, i, n, m);

            if (max5 < top * mid * bot) {
                max5 = top * mid * bot;
            }
        }
    }

    long long max6 = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            long long top = getArea(0, 0, j, i);
            long long mid = getArea(j, 0, n, i);
            long long bot = getArea(0, i, n, m);

            if (max6 < top * mid * bot) {
                max6 = top * mid * bot;
            }
        } 
    }

    max.push_back(max1);
    max.push_back(max2);
    max.push_back(max3);
    max.push_back(max4);
    max.push_back(max5);
    max.push_back(max6);

    sort(max.begin(), max.end());

    cout << max.back();
}