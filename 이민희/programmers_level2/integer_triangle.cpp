#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> dp;

int solution(vector<vector<int>> triangle) {
    dp = triangle;
    for (int i = 0; i < triangle.size() - 1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
        }
    }
    
    vector<int> tmp = dp[dp.size() - 1];
    sort(tmp.begin(), tmp.end());
    int answer = tmp[tmp.size() - 1];
    return answer;
}