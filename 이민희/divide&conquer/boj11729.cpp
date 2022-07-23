#include <iostream>
using namespace std;

int countresult(int n){
    if (n == 1)
        return 1;
    else if (n == 2)
        return 3;
    else {
        return (countresult(n - 1) * 2 + 1);
    }
}

void hanoi(int num, int start, int via, int dest){
    if (num == 1){
        cout << start << " " << dest << '\n';
        return;
    }
    else if (num == 2)
    {
        cout << start  << " " << via << '\n';
        cout << start  << " " << dest << '\n';
        cout << via  << " " << dest << '\n';
        return;
    }
    else {
        hanoi(num - 1, start, dest, via);
        cout << start  << " " << dest << '\n';
        hanoi(num - 1, via, start, dest);
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;
    
    cout << countresult(n) << '\n';
    hanoi(n, 1, 2, 3);
}