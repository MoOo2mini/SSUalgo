#include <stack>
#include <iostream>
#include <string>
using namespace std;

bool Check(string s){

    int flag = 0;
    stack<char> st;
    for (int i=0;i<s.size();i++){
        char c = s[i];
        if (c == '('){
            st.push('(');
        }
        else if (c == ')'){
            if (st.empty()){
                return false;
            }
            st.pop();
        }
    }
    
    if (flag || !st.empty()) return false;
    return true;
}

int main(){

    int count;
    
    cin >> count;

    for (int k = 0; k < count; k++)
    {
        string str;
        cin >> str;

        if (Check(str))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}