#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main(){
    while (1){
        stack <char> st;
        string s;
        getline(cin, s);
        
        if (s=="."){
            break;
        }
        int flag = 0;
        for (int i=0;i<s.size();i++){
            char c = s[i];
            if (c == '(' || c=='['){
                st.push(c);
            }
            else if (c == ')'){
                if (st.empty() || st.top()!='('){
                    flag = 1;
                    break;
                }
                st.pop();
            }
            else if (c == ']'){
                if (st.empty() || st.top()!='['){
                    flag = 1;
                    break;
                }
                st.pop();
            }
        }
        
        if (flag || !st.empty()) cout << "no\n";
        else cout << "yes\n";
        
    }
    
    return 0;
    
}