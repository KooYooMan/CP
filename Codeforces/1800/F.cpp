#include<iostream>
#include<map>
#include<algorithm>

const int MAX_N = 2e5 + 10;

int existanceMask[MAX_N];
int oddMask[MAX_N];
int candidates[MAX_N];

int main() {

	int n; std::cin >> n;

	for (int i = 0; i < n; i ++) {
		std::string s; std::cin >> s;

		for (char c: s) {
			existanceMask[i] |= (1 << (c - 'a'));
			oddMask[i] ^= (1 << (c - 'a'));
		}
	}

	long long ans = 0;

	for (int i = 0; i < 26; i ++) {
		int ultimate_mask = (1 << 26) - 1 - (1 << i);

		int num_candidates = 0;
		for (int j = 0; j < n; j ++) {
			if ((existanceMask[j] & (1 << i))) continue;
			candidates[num_candidates ++] = oddMask[j];
		}
		std::sort(candidates, candidates + num_candidates);

		for (int j = 0; j < n; j ++) {
			if ((existanceMask[j] & (1 << i))) continue;
			int* l = std::lower_bound(candidates, candidates + num_candidates, ultimate_mask - oddMask[j]);
			int* r = std::upper_bound(candidates, candidates + num_candidates, ultimate_mask - oddMask[j]);
			ans += 1ll * (r - l);
		}
	}

	std::cout << ans / 2 << "\n";

	return 0;
}
