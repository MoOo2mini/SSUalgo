#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> positive;
vector<int> negative;
int result;
int zero_count;

int greedy() {
    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end(), less<int>());

    for (int i = 0; i < positive.size() - (positive.size()%2); i += 2) {
        result += positive[i] * positive[i + 1];
    }
    if (positive.size() % 2 == 1) {
        result += positive.back();
    }

    for (int i = 0; i < negative.size() - (negative.size()%2); i += 2) {
        result += negative[i] * negative[i + 1];
    }
    if ((negative.size() % 2 == 1) && (zero_count == 0)) {
        result += negative.back();
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp > 1) {
            positive.push_back(tmp);
        } else if (tmp == 1) {
            result += 1;
        } else if (tmp == 0) {
            zero_count += 1;
        } else {
            negative.push_back(tmp);
        }
    }

    cout << greedy() << endl;
}