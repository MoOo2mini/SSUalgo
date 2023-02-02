#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stu {
    string name;
    int kor, eng, math;
};

bool compare(stu a, stu b) {
    if (a.kor == b.kor) {
        if (a.eng == b.eng) {
            if (a.math == b.math) {
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.eng < b.eng;
    }
    
    return a.kor > b.kor;
}

int main() {
    int n;
    cin >> n;

    vector<stu> v;
    stu s;
    for (int i = 0; i < n; i++) {
        cin >> s.name >> s.kor >> s.eng >> s.math;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++) {
        cout << v[i].name << '\n';
    }
}