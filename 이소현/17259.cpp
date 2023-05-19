#include <iostream>
#include <vector>

using namespace std;

struct Emyloyee{
    int y;
    int x;
    int t;
};
void solve(){
    int b, n, m;
    cin>>b>>n>>m;

    int** belt = new int*[b];
    vector<Emyloyee> e;
    for(int i=0;i<b;i++){
        belt[i] = new int[b];
        for(int j=0;j<b;j++){
            belt[i][j]=0;
        }
    }

    int dx[]={-1,0,1};

    for(int i=0;i<n;i++){
        Emyloyee tmp;
        cin>>tmp.x>>tmp.y>>tmp.t;
        e.push_back(tmp);
    }
    int ans=0;
    int put=0;
    for(int i=0;i<m+b*3-2;i++){
        //선물을 컨베이어 돌리기
        int x, y;
        for(y=0, x = b-1 ;y<b-1;y++){
            belt[x][y]=belt[x][y+1];
        }
        for(y=b-1,x=b-1;x>0;x--){
            belt[x][y]=belt[x-1][y];
        }
        for(y=b-1, x=0;y>0;y--){
            belt[x][y]=belt[x][y-1];
        }
        if(put<m){
            belt[0][0]=1; //선물 추가
            put++;
        }


        for(auto emp = e.begin(); emp != e.end(); emp++){
            if(belt[emp->x][emp->y]){
                belt[emp->x][emp->y]--;
                continue;
            }
        
            // 직원 상하좌우에 선물 있으면
            for(int dx : {-1, 0, 1}){
                int yarr[3];
                if(dx==-1){
                    for(int dy:{-1,0,1}){
                        int bx = emp->x + dx;
                        int by = emp->y + dy;
                        if(belt[bx][by]){
                            belt[bx][by]=0;
                            belt[emp->x][emp->y]=emp->t;
                            ans++;
                            break;
                        }
                    }
                }else if(dx==0){
                    for(int dy:{1}){
                        int bx = emp->x + dx;
                        int by = emp->y + dy;
                        if(belt[bx][by]){
                            belt[bx][by]=0;
                            belt[emp->x][emp->y]=emp->t;
                            ans++;
                            break;
                        }
                    }
                }if(dx==1){
                    for(int dy:{1,0,-1}){
                        int bx = emp->x + dx;
                        int by = emp->y + dy;
                        if(belt[bx][by]){
                            belt[bx][by]=0;
                            belt[emp->x][emp->y]=emp->t;
                            ans++;
                            break;
                        }
                    }
                }
                if(belt[emp->x][emp->y]){
                    break;
                }
            }//선물 확인
        }//for(emp)
        
        for(int j=0;j<b;j++){
            for(int k=0;k<b;k++){
                cout<<belt[j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
    }
    cout<<ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}