#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;

int a[MAXN], t[MAXN];

int result[MAXN];

int main() {
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;

	while (nTest --) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < k; i ++) {
			cin >> a[i];
		}
		for (int i = 0; i < k; i ++) {
			cin >> t[i];
		}
		for (int i = 0; i < n; i ++) {
			result[i] = (int)2e9;
		}
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < k; i ++) {
			q.push(make_pair(-t[i], a[i] - 1));
		}
		while (!q.empty()) {
			int value = -q.top().first;
			int pos = q.top().second;
			q.pop();
			if (result[pos] <= value) {
				continue;
			}
			result[pos] = value;
			if (pos && result[pos - 1] > value + 1) {
				q.push(make_pair(-value - 1, pos - 1));
			}
			if (pos + 1 < n && result[pos + 1] > value + 1) {
				q.push(make_pair(-value - 1, pos + 1));
			}
		}
		for (int i = 0; i < n; i ++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}
