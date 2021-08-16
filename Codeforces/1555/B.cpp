#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;
	cout << fixed << setprecision(6);

	while (nTest --) {
		int W, H; cin >> W >> H;
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int w, h; cin >> w >> h;
		int ans = INF;
		if (x2 - x1 + w <= W) {
			ans = min(ans, max(0, w - x1));
			ans = min(ans, max(0, x2 + w - W));
		}
		if (y2 - y1 + h <= H) {
			ans = min(ans, max(0, h - y1));
			ans = min(ans, max(0, y2 + h - H));
		}
		if (ans == INF) {
			cout << -1 << "\n";
		} else {
			cout << double(ans) << "\n";
		}
	}

	return 0;
}
