#include <iostream>
#include <stack>
using namespace std;

int main(){
	int num;
	int arrIdx = 0;
	int i = 1;
	stack<int> stk;

	cin >> num;
	int arr[num];

	int noIdx = 0;
	char no[num * 2 + 1];

	for (int k = 0; k < num; k++)
		cin >> arr[k];

	while (arrIdx < num)
	{
		while (i <= arr[arrIdx]){
			stk.push(i); 
			no[noIdx++] = '+';
			if (i == num) break;
			i++;
		}
		if (stk.empty() != true && stk.top() == arr[arrIdx]) {
			stk.pop();
			no[noIdx++] = '-';
		}
		else
		{
			cout << "NO" << '\n';
			return (0);
		}
		arrIdx++;
	}

	if (noIdx != num * 2)
	{
		cout << "NO" << '\n';
		return 0;
	}

	for (int i = 0; i < num * 2; i++)
		cout << no[i] << '\n';
}
