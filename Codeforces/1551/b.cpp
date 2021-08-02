#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
pair<int, int> a[MAXN];
int c[MAXN];
vector<pair<int,int>> Candidate;

int main() {
  // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

  int nTest; cin >> nTest;

  while (nTest --) {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++ i) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a, a+n);
    int count = 1;
    Candidate.push_back(a[0]);
    for (int i = 1; i < n; ++ i) {
      if (a[i].first != a[i-1].first) {
        count = 1;
      }
      else {
        count ++;
      }

      if (count > k) {
        continue;
      }

      Candidate.push_back(a[i]);
    }

    while ((int)Candidate.size() % k) Candidate.pop_back();

    for (int i = 0; i < (int)Candidate.size(); ++ i) {
      c[Candidate[i].second] = i % k + 1;
    }

    for (int i = 0; i < n; ++ i) {
      cout << c[i] << " ";
      c[i] = 0;
    }
    cout << "\n";
    Candidate.clear();
  }

  return 0;
}
