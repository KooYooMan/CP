#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;
const int MAXM = 1e6 + 10;

struct segment {
	int l;
	int r;
	int w;
	segment() : l(0), r(0), w(0) {}
	segment(int _l, int _r, int _w) : l(_l), r(_r), w(_w) {}
} a[MAXN];

bool compare_segment(segment x, segment y) {
	return x.w < y.w;
}

struct group {
	int value;
	vector<pair<int, int>> listSegment;
	group() {
		value = 0;
		listSegment.clear();
	}
	group(segment x) {
		value = x.w;
		listSegment.clear();
		listSegment.push_back(make_pair(x.l, x.r));
	}
};

vector<group> listGroup;

int tree[4 * MAXM];
int lazy[4 * MAXM];

void initTree(int id, int l, int r) {
	if (l == r) {
		tree[id] = 0;
		return;
	}
	int mid = (l + r) / 2;
	initTree(2 * id, l, mid);
	initTree(2 * id + 1, mid + 1, r);
	tree[id] = 0;
	lazy[id] = 0;
}

void lazy_update(int id) {
	tree[2 * id] += lazy[id];
	tree[2 * id + 1] += lazy[id];
	lazy[2 * id] += lazy[id];
	lazy[2 * id + 1] += lazy[id];
	lazy[id] = 0;
}

void update(int id, int l, int r, int l1, int r1, int value) {
	if (l > r1 || r < l1) {
		return ;
	}
	if (l >= l1 && r <= r1) {
		lazy[id] += value;
		tree[id] += value;
		return;
	}
	lazy_update(id);
	int mid = (l + r) / 2;
	update(2 * id, l, mid, l1, r1, value);
	update(2 * id + 1, mid + 1, r, l1, r1, value);
	tree[id] = min(tree[2 * id], tree[2 * id + 1]);
}

int main() {
	freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i ++) {
		int l, r, w; cin >> l >> r >> w;
		a[i] = segment(l, r, w);
	}

	sort(a, a + n, compare_segment);

	group firstGroup = group(a[0]);
	listGroup.push_back(firstGroup);

	for (int i = 1; i < n; i ++) {
		if (a[i].w == a[i-1].w) {
			listGroup[(int)listGroup.size() - 1].listSegment.push_back(make_pair(a[i].l, a[i].r));
		} else {
			group newgroup = group(a[i]);
			listGroup.push_back(newgroup);
		}
	}

	initTree(1, 1, m - 1);

	int l = 0, r = -1;
	
	int ans = (int)1e9;

	while(r < (int)listGroup.size() - 1) {
		while (tree[1] == 0 && r + 1 < (int)listGroup.size()) {
			r ++;
			for (auto seg: listGroup[r].listSegment) {
				int l_seg = seg.first, r_seg = seg.second;
				update(1, 1, m - 1, l_seg, r_seg - 1, 1);
			}
		}
		if (tree[1] == 0) break;
		while (l <= r) {
			for (auto seg: listGroup[l].listSegment) {
				int l_seg = seg.first, r_seg = seg.second;
				update(1, 1, m - 1, l_seg, r_seg - 1, -1);
			}
			l ++;
			if (tree[1] == 0) break;
		}
		ans = min(ans, listGroup[r].value - listGroup[l - 1].value);
	}
	
	cout << ans << "\n";

	return 0;
}
