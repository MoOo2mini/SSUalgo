#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (s / n == 0) {
        answer.push_back(-1);
        return answer;
    }
    
    int div = s / n;
    int mod = s % n;
    for (int i = 0; i < n; i++) {
        answer.push_back(div);
    }
    for(int i = 1; i <= s % n; i++)
        answer[n - i]++;
    return answer;
}
