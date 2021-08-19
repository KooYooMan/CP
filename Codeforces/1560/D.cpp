#include<bits/stdc++.h>
using namespace std;

map<long long, int> f;

int main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	
	for (long long x = 1; x <= (long long)1e18; x *= 2) {
		long long num = x;
		vector<int> listDigit;
		while (num) {
			listDigit.push_back(num % 10);
			num /= 10;
		}
		int nDigit = (int)listDigit.size();
		reverse(listDigit.begin(), listDigit.end());

		num = x;
		long long y = 0;
		for (int i = 0; i < 9 && i < (int)listDigit.size(); i ++) {
			int digit = listDigit[i];
			y *= 10;
			y += 1ll * digit;
			if (f.find(y) == f.end()) {
				f[y] = nDigit - (i + 1);
			} else {
				f[y] = min(f[y], nDigit - (i + 1));
			}
		}
	}

	f[0] = 1;

	int nTest; cin >> nTest;

	while (nTest --) {
		int n; cin >> n;
		int num = n;
		vector<int> digit;
		while (num) {
			digit.push_back(num % 10);
			num /= 10;
		}
		int nDigit = (int)digit.size();
		reverse(digit.begin(), digit.end());
		int ans = 100;
		for (int mask = 0; mask < (1 << nDigit); mask ++) {
			int curNum = 0;
			int nRemainDigit = 0;
			bool ok = true;
			for (int i = 0; i < nDigit; i ++) {
				if (mask & (1 << i)) {
					curNum *= 10; curNum += digit[i];
					if (curNum == 0) {
						ok = false;
						break;
					}
					nRemainDigit ++;
				}
			}
			if (!ok) {
				continue;
			}
			if (f.find(1ll * curNum) == f.end()) {
				continue;
			} else {
				ans = min(ans, f[1ll * curNum] + nDigit - nRemainDigit);
			}
		} 
		cout << ans << "\n";
	}

	return 0;
}
