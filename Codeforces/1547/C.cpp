#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
int a[MAXN], b[MAXN];

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest; 
	
	while (nTest --) {
		int k, m, n; cin >> k >> m >> n;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int i_a = 0, i_b = 0;
		vector<int> result{};
		bool ok = true; 
		while (i_a < m || i_b < n) {
			int value = -1;
			if (i_a >= m) {
				value = b[i_b++];
			} else if (i_b >= n) {
				value = a[i_a++];
			}

			if (value == -1) {
				if (a[i_a] < b[i_b]) {
					value = a[i_a++];
				} else {
					value = b[i_b++];
				}
			}
			if (value > k) {
				ok = false;
				break;
			}
			if (value == 0) {
				k ++;
			}
			result.push_back(value);
		}
		if (!ok) {
			cout << -1 << "\n";
		} else {
			for (int element: result) {
				cout << element << " ";
			}
			cout << "\n";
		}
	}

	return 0;
 }
