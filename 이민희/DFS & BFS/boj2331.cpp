#include <iostream>
#include <cmath>
using namespace std;
 
void dfs(int x);
 
int visited[300001] = {0};
int A, P;
 
int main(int argc, const char * argv[]) {
    int count = 0;
    cin >> A >> P;
    
    dfs(A);
    for(int i = 0; i < 300001; i++){
        if(visited[i] == 1)
            count++;
    }
    cout << count << '\n';
    return 0;
}
 
void dfs(int x){ // 이것도 dfs??
    visited[x]++;
    if(visited[x] == 3) // 2가 아닌 3인 이유는 반복하는 모든 수를 찾아 2를 만들어야하기 때문이다.
        return;
    int sum = 0;
    while(x){
        sum += (int)pow((x % 10), P);
        x /= 10;
    }
    dfs(sum);
}
 