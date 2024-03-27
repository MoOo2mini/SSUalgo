#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    time_t timer;
    timer = time(NULL);
    struct tm* t = localtime(&timer);

    int year, month, day;
    year = t->tm_year + 1900;
    month = t->tm_mon + 1;
    day = t->tm_mday;

    cout << year << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day;
}