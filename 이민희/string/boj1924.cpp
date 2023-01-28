#include <iostream>
using namespace std;

int main() {
    int month, date;

    cin >> month >> date;

    int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
    int result = 0;
    result += date;
    for (int i = 0; i < (month - 1); i++) {
        result += daysInMonth[i];
    }

    switch (result % 7) {
    case 0:
        cout << "SUN";
        break;
    case 1:
        cout << "MON";
        break;
    case 2:
        cout << "TUE";
        break;
    case 3:
        cout << "WED";
        break;
    case 4:
        cout << "THU";
        break;
    case 5:
        cout << "FRI";
        break;
    case 6:
        cout << "SAT";
        break;
    }
}