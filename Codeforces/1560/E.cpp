#include<bits/stdc++.h>
using namespace std;

int num[26];
int temp[26];
int pos[26];

int main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int nTest; cin >> nTest;

	while (nTest --) {
		string t; cin >> t;
		vector<char> order;
		for (int i = 0; i < 26; i ++) {
			num[i] = 0;
			pos[i] = -1;
			temp[i] = 0;
		}
		for (int i = (int)t.size() - 1; i >= 0; i --) {
			int x = t[i] - 'a';
			if (num[x] == 0) {
				pos[x] = (int)order.size();
				order.push_back(t[i]);
			}
			num[x] ++;
		}
		int k = (int)order.size();
		bool ok = true;
		for (int i = 0; i < (int)order.size(); i ++) {
			char c = order[i];
			if (num[c - 'a'] % (k - i)) {
				ok = false;
				break;
			}
			num[c - 'a'] /= (k - i);
		}
		if (!ok) {
			cout << -1 << "\n";
			continue;
		}
		int savedCheckpoint = 0;
		int lastCheckpoint = (int)t.size();
		int patternPos = (int)t.size();
		for (int i = 0; i < k; i ++) {
			int fullfil = 0;
			while (fullfil < i + 1) {
				lastCheckpoint --;
				int x = t[lastCheckpoint] - 'a';
				if (pos[x] > i) {
					ok = false;
					break;
				}
				if (pos[x] < i) {
					patternPos --;
					if (t[patternPos] != t[lastCheckpoint]) {
						ok = false;
						break;
					}
				}
				temp[x] ++;
				if (temp[x] > num[x] * (i - pos[x] + 1)) {
					ok = false;
					break;
				}
				if (temp[x] == num[x] * (i - pos[x] + 1)) {
					fullfil ++;
				}
			}
			if (!ok) {
				break;
			}
			savedCheckpoint = patternPos;
		}
		if (!ok) {
			cout << -1 << "\n";
		} else {
			for (int i = 0; i < savedCheckpoint; i ++) cout << t[i];
			cout << " ";
			reverse(order.begin(), order.end());
			for (char c: order) cout << c;
			cout << "\n";
		}
	}

	return 0;
}
