#include <iostream>
using namespace std;
int n;

bool find(int c, const int *arr)
{
    for (int i = 0; i < n; i++)
        if (c == arr[i]) return true;
    return false;
}

int main()
{
    int count1 = 0;
    int count2 = 0;

    int result1 = 0;
    int result2 = 0;

    string num;
    cin >> num;

    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];

    if (num == "100"){
        cout << '0';
        return 0;
    }
    
    int temp1;
    for (int i = 0; i < num.length(); i++)
    {
        temp1 = num[i] - '0'; // 5457 --> 5

        while (true){
            if (find(temp1, nums)) temp1++;
            else{
                count1++;
                result1 = result1 * 10 + temp1;
                break;
            }
        }
    }

    int temp2;
    for (int i = 0; i < num.length(); i++)
    {
        temp2 = num[i] - '0'; // 5457 --> 5

        while (true){
            if (find(temp2, nums)) {
                if (i == 0) {num = to_string(stoi(num) - 1); count2++;}
                temp2--;
            }
            else{
                count2++;
                result2 = result2 * 10 + temp2;
                break;
            }
        }
    }

    count1 += (result1 - stoi(num));
    count2 -= (result2 - stoi(num));

    if (count1 < count2)
        cout << count1;
    else
        cout << count2;
}