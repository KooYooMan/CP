#include<iostream>
#include<queue>

std::priority_queue<int> q;

const int MAX_N = 5e3 + 10;

int s[MAX_N];

void solve() {
	int n; std::cin >> n;

	while(!q.empty()) q.pop();

	long long ans = 0;
	for (int i = 0; i < n; i ++) {
		int x; std::cin >> x;
		if (x == 0) {
			if (!q.empty()) {
				ans += 1ll * q.top();
				q.pop();
			}
		} else {
			q.push(x);
		}
	}

	std::cout << ans << "\n";
}

int main() {

	int nTest; std::cin >> nTest;

	for (int i = 0; i < nTest; i ++) {
		solve();
	}

	return 0;
}
