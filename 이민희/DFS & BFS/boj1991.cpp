#include <iostream>
using namespace std;

int n;
int arr[27][2];

void preorder(char root) {
    cout << root;

    for (int i = 0; i < 2; i++) {
        char next = arr[root-'A'][i]; //인덱스 char 타입으로 변환
		if (next !='.') //노드가 비어있지 않으면
			preorder(next);
    }

    return;
}

void inorder(char root) {
    char next = arr[root - 'A'][0];
    if (next != '.') {
        inorder(next);
    }
    
    cout << root;

    next = arr[root - 'A'][1];
    if (next != '.') {
        inorder(next);
    }

    return;
}

void postorder(char root) {
    char next = arr[root - 'A'][0];
    if (next != '.') {
        postorder(next);
    }

    next = arr[root - 'A'][1];
    if (next != '.') {
        postorder(next);
    }

    cout << root;

    return;
}

int main() {
    cin >> n;

    char parent, right, left;
    for (int i = 0; i < n; i++) {
        cin >> parent >> left >> right;

        arr[parent - 'A'][0] = left;
        arr[parent - 'A'][1] = right;
    }

    preorder('A');
    cout << "\n";

	inorder('A');
	cout << "\n";

	postorder('A');
	cout << "\n";
}