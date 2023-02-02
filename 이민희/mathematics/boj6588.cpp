	#include <iostream>
 
using namespace std;
 
 
#define MAX 1000000
 
int primeArr[MAX] = {0};
 
void primeChk(){
    
    for(int i = 2; i*i<=MAX; i++){
        
        if(primeArr[i]==0){
        
            for(int j = i*i; j<=MAX; j+=i){
                primeArr[j] = 1;
            }
        }
        
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    primeChk();
 
    
    while(1){
        
        cin >> n;
        if(n==0){
            break;
        }
                   
        bool chk = false;
        
        for(int a = 3; a<= n; a+=2){
           // int b = n - a;
            if(primeArr[a]==0 && primeArr[n-a]==0) {    //a가
                cout << n << " = " << a << " + " << n-a << "\n";
                chk = true;
                break;
            }
        }
        if(!chk){
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
  
    
    return 0;
}
 