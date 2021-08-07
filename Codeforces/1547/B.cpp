#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;
	
	while (nTest --) {
		string s; cin >> s;
		deque<char> q;
		bool ok = true;
		for (char c: s) {
			q.push_back(c);
		}
		int indice = (int)s.size();
		while (!q.empty()) {
			indice --;
			int value_front = q.front() - 'a';
			int value_back = q.back() - 'a';
			if (value_front == indice) {
				q.pop_front();
				continue;
			}
			if (value_back == indice) {
				q.pop_back();
				continue;
			}
			ok = false;
			break;
		}
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
};
