#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int a[MAXN];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;

	while (nTest --) {
		int n; cin >> n;
		int value = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			value |= a[i];
			int result = value^a[i];
			cout << result << " ";
		}
		cout << "\n";
	}

	return 0;
 }
