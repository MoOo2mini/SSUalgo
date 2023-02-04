#include <string>
#include <vector>

using namespace std;
int answer = 0;

void get_result(vector<int> numbers, int target, int num, int index) {
    if (index == numbers.size()) {
        if (num == target) {
            answer++;
        }
        return;
    }
    
    get_result(numbers, target, num + numbers[index], index + 1);
    get_result(numbers, target, num - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    get_result(numbers, target, 0, 0);
    return answer;
}