#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, m;
	vector<int> v;
	cin>>n;
	for(int i=0; i<n; i++) {
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for(int i=0; i<m; i++) {
		int b;
		cin>>b;
		if(binary_search(v.begin(), v.end(), b))
			cout<<1<<'\n';
		else
			cout<<0<<'\n';
	}
}