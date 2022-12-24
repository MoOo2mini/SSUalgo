#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstring>

using namespace std;

struct Commend {
    int a,d,m,c;

    int count;
    string result;
};

int main() {
    char S[17000];
    char T[17000];

    cin >> S;
    cin >> T;

    Commend arr[strlen(S) + 1][strlen(T) + 1];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i <= strlen(S); i++) {
        arr[i][0].count = i;
    }
    for (int i = 0; i <= strlen(T); i++) {
            arr[0][i].count = i;
    }

    for (int i = 1; i <= strlen(S); i++) {
        for (int j = 1; j <= strlen(T); j++) {
            Commend A = arr[i][j - 1];
            Commend D = arr[i - 1][j];
            Commend MC = arr[i - 1][j - 1];

            int MCcount;
            if (MC.count && S[i] == T[j]) {
                MCcount = MC.count;
            } else {
                MCcount = MC.count + 1;
            }

            int minValue = min(min(A.count + 1, D.count + 1), MCcount);
            if (minValue == A.count + 1) {
                arr[i][j].result += arr[i][j - 1].result + "a";
                arr[i][j].a += A.a + 1;
                arr[i][j].d += A.d;
                arr[i][j].m += A.m;
                arr[i][j].c += A.c;
                arr[i][j].count = A.count + 1;
            } else if (minValue == D.count + 1) {
                arr[i][j].result += arr[i - 1][j].result + "d";
                arr[i][j].d += D.d + 1;
                arr[i][j].a += D.a;
                arr[i][j].m += D.m;
                arr[i][j].c += D.c;
                arr[i][j].count = D.count + 1;
            } else if (minValue == MCcount && (S[i] != T[j])) {
                arr[i][j].result += arr[i - 1][j - 1].result + "m";
                arr[i][j].m = MC.m+1;
                arr[i][j].a += MC.a;
                arr[i][j].d += MC.d;
                arr[i][j].c += MC.c;
                arr[i][j].count = MCcount;
            } else {
                arr[i][j].result += arr[i - 1][j - 1].result + "c";
                arr[i][j].c += MC.c+1;
                arr[i][j].a += MC.a;
                arr[i][j].d += MC.d;
                arr[i][j].m += MC.m;
                arr[i][j].count = MC.count;
            }
        }
    }

    cout << "a : " << arr[strlen(S)][strlen(T)].a << endl;
    cout << "d : " << arr[strlen(S)][strlen(T)].d << endl;
    cout << "m : " << arr[strlen(S)][strlen(T)].m << endl;
    cout << "c : " << arr[strlen(S)][strlen(T)].c << endl;
    cout << "count : " << arr[strlen(S)][strlen(T)].count << endl;
    cout << "result : " << arr[strlen(S)][strlen(T)].result;
}