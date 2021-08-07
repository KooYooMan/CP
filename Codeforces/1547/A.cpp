#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;

	for (int i = 0; i < nTest; ++ i) {
		int xA, yA; cin >> xA >> yA;
		int xB, yB; cin >> xB >> yB;
		int xC, yC; cin >> xC >> yC;

		int ans = abs(xA - xB) + abs(yA - yB);
		if (xA == xB) {
			if (yC > min(yA, yB) && yC < max(yA, yB) && xC == xA) {
				ans += 2;
			}
		}
		if (yA == yB) {
			if (xC > min(xA, xB) && xC < max(xA, xB) && yC == yA) {
				ans += 2;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
