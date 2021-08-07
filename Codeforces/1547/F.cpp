#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int a[2 * MAXN][20];

int get(int l, int r) {
	int level = log2(r - l + 1);
	return __gcd(a[l][level], a[r - (1 << level) + 1][level]);
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;

	while (nTest --) {
		int n; cin >> n;
		int global_gcd = 0;
		for (int i = 0; i < n; i ++) {
			cin >> a[i][0];
			global_gcd = __gcd(global_gcd, a[i][0]);
		}
		for (int i = n - 1; i >= 0; i --) {
			for (int j = 1; j < 20; j ++) {
				a[i][j] = a[i][j - 1];
				if (i + (1 << (j - 1)) < n) {
					a[i][j] = __gcd(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
				}
			}
		}
		int l = 0, r = n - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			bool ok = true;
			for (int i = 0; i < n; i ++) {
				int ans = 0;
				if (i + mid >= n) {
					ans = __gcd(get(i, n-1), get(0, (i + mid) % n));
				} else {
					ans = get(i, i + mid);
				}
				if (ans != global_gcd) {
					ok = false;
					break;
				}
			}
			if (ok) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		cout << l << "\n";
	}

	return 0;
}
