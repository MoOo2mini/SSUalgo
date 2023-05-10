#include <iostream>
using namespace std;

#define INF 1000000000
int N, M, B;
int board[502][502];

int check(int board[][502], int lv, int b){
    int sc = 0;
    int c = 0; // 채워넣어야하는 블록의 개수
    for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
            int z = board[i][j] - lv;
            if (z > 0){
                b += z;
                sc += 2*z;
            }
            else
                c += -z;
        }
    
    if (b < c)
        return INF;
    return sc + c;
}

int main(){
    int msc = INF;
    int sc;
    int mlv = 0;

    // sc - time, lv = level(height)
    cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
    for (int lv = 256; lv >= 0; lv--){
        sc = check(board, lv, B);
        if (msc > sc)
        {
            msc = sc;
            mlv = lv;
        }
    }
    cout << msc << " " << mlv;
}