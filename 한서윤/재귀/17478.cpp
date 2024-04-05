#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void chat(int n, int cnt);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, result, cnt = 0;
	cin >> n;
	chat(n, cnt);	
}

void chat(int n, int cnt) {
	if (cnt == 0) cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
	string line = "";
	for (int i = 0; i < cnt; i++) line.append("____");
	if (n == 0) {
		cout << line << "\"����Լ��� ������?\"" << '\n';
		cout << line << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
		cout << line << "��� �亯�Ͽ���." << '\n';
		}
	else {
		cout << line << "\"����Լ��� ������?\""<<'\n';
		cout << line << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
		cout << line << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
		cout << line << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';
		chat(n - 1, ++cnt);
		cout << line << "��� �亯�Ͽ���." << '\n';
	}
}