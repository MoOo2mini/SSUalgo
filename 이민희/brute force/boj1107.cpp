#include <iostream>

using namespace std;

bool checkChannel(int currentChannel, bool buttons[10]) {
    string str = to_string(currentChannel);
    
    for (int i = 0; i < str.length(); i++) {
        if (buttons[str[i] - 48])
            return false;
    }
    
    return true;
}

int main() {
    int targetChannel;
    int buttonSize;
    bool buttons[10] = { false };
    
    cin >> targetChannel >> buttonSize;
    string targetString = to_string(targetChannel);
    int minNum = abs(targetChannel - 100);
    
    for (int i = 0; i < buttonSize; i++) {
        int num;
        cin >> num;
        buttons[num] = true;
    }
    
    for (int i = 0; i <= 1000000; i++)  {
        if(checkChannel(i, buttons)){
            int num = abs(targetChannel-i) + to_string(i).length();
            minNum = min(minNum, num);
        }
    }
    
    cout << minNum << endl;
}