#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int num[MAXN][3][3];

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;

	string s; cin >> s;
	
	for (int i = 0; i < n; i ++) {
		if (i > 0) {
			for (int mod = 0; mod < 3; mod ++) {
				for (int character = 0; character < 3; ++ character) {
					num[i][mod][character] = num[i - 1][mod][character];
				}
			}
			
		}
		num[i][i % 3][s[i] - 'a'] ++;
	}

	for (int i = 0; i < m; i ++) {
		int l, r; cin >> l >> r;
		l --; r --;
		string form = "abc";
		int ans = r - l + 1;
		do {
			int cost = 0;
			for (int i = 0; i < 3; i ++) {
				int total = r / 3 - l / 3 + 1;
				if (r % 3 < i) total --;
				if (l % 3 > i) total --;
				total -= num[r][i][form[i] - 'a'];
				if (l) {
					total += num[l - 1][i][form[i] - 'a'];
				}
				cost += total;
			}
			ans = min(ans, cost);
		} while (next_permutation(form.begin(), form.end()));
		cout << ans << "\n";
	}

	return 0;
}
