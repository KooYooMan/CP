#include<bits/stdc++.h>
using namespace std;

bool used[10];

int main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;

	while (nTest --) {
		int n, k; cin >> n >> k;
		vector<int> digit;
		int num = n;
		while (num) {
			digit.push_back(num % 10);
			num /= 10;
		}
		reverse(digit.begin(), digit.end());
		for (int i = 0; i < 10; i ++) used[i] = false;
		int limit;
		int count = 0;
		for (int i = 0; i < (int)digit.size(); i ++) {
			if (!used[digit[i]]) {
				count ++;
				if (count > k) {
					break;
				}
			}
			used[digit[i]] = true;
			limit = i;
		}
		if (count <= k) {
			cout << n << "\n";
			continue;
		}
		for (int i = limit + 1; i >= 0; -- i) {
			int count = 0;
			for (int j = 0; j < 10; j ++) used[j] = false;
			for (int j = 0; j < i; j ++) {
				if (!used[digit[j]]) {
					count ++;
					used[digit[j]] = true;
				}
			}
			int d = digit[i];
			if (d == 9) continue;
			int nextDigit = -1;
			if (count < k) {
				nextDigit = d + 1;
				if (!used[d + 1]) {
					used[d + 1] = true;
					count ++;
				}
			} else {
				for (int j = d + 1; j < 10; j ++) {
					if (used[j]) {
						nextDigit = j;
						break;
					}
				}
			}
			if (nextDigit == -1) {
				continue;
			}
			int remainDigit;
			if (count < k) {
				remainDigit = 0;
			} else {
				for (int j = 0; j < 10; j ++) {
					if (used[j]) {
						remainDigit = j;
						break;
					}
				}
			}
			for (int j = 0; j < i; j ++) cout << digit[j];
			cout << nextDigit;
			for (int j = i + 1; j < (int)digit.size(); j ++) cout << remainDigit;
			cout << "\n";
			break;
		}
	}
	return 0;
}
