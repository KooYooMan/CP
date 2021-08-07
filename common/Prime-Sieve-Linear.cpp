#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int f[N]; // f[i] = minimum prime factor of n
vector<int> prime; // list of prime

void SoE(int limit) { // Sieve of Eratosthenes
	for (int i = 2; i < limit; i ++) {
		if (f[i] == 0) {
			f[i] = i;
			prime.push_back(i);
		}
		for (int j = 0; j < (int)prime.size() && prime[j] <= f[i] && i * prime[j] <= limit; j ++) {
			f[i * prime[j]] = prime[j];
		}
	}
}

int main() {

	// just for testing
	SoE((int)1e6);
	assert(f[2] == 2);
	assert(f[4] == 2);
	assert(f[10] == 2);
	assert(f[13] == 13);

	for (int i = 0; i < 10; i ++) {
		cout << prime[i] << " ";
	}
	cout << "\n";

	return 0;
}
