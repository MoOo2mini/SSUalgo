#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;


void bubbleSort(vector<int> &vec) { // 1,000,000의 경우 끝나지 않음. 시간이 매애애애애애우 오래걸림.
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec.at(j) > vec.at(j + 1))
                std::swap(vec.at(j), vec.at(j + 1));
        }
    }
}

int main() {
    clock_t start, finish;
    double duration;
    vector<int> v;

    srand(time(NULL));

    for (int i = 0; i < 1000000; i++) {
        v.push_back(rand() % 100);
    }
    
    start = clock();
 
    /*실행 시간을 측정하고 싶은 코드*/
    bubbleSort(v); // 1,000,000의 경우 끝나지 않음. 시간이 매애애애애애우 오래걸림.
    // sort(v.begin(), v.end()); // 1,000,000의 경우 0.03초에서 끝났다.
    
    finish = clock();
    
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초\n";
    
    return 0;
}