#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

struct segmentTree {
    int size;
    vector<long long> tree;
    long long NEUTRAL_ELEMENT= 0LL;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, NEUTRAL_ELEMENT);
    }

    long long merge(long long a, long long b) {
        return a + b;
    }

    void build(vector<int> &v) {
        int n = v.size();
        init(n);
        for (int i = 0; i < n; i++) {
            tree[i + size] = v[i];
        }
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void set(int i, int val) {
        set(i, val, 1, 0, size - 1);
    }

    void set(int i, int val, int x, int lx, int rx) {
        if (lx == rx) {
            tree[x] += val;
            return;
        }
        int m = lx + (rx - lx) / 2;
        if (i <= m) set(i, val, 2 * x, lx, m);
        else set(i, val, 2 * x + 1, m + 1, rx);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    long long solve(int l, int r) {
        return solve(l, r, 1, 0, size - 1);
    }

    long long solve(int l, int r, int x, int lx, int rx) {
        if (lx > r or rx < l) return NEUTRAL_ELEMENT;
        if (lx >= l and rx <= r) return tree[x];
        int m = lx + (rx - lx) / 2;
        long long s1 = solve(l, r, 2 * x, lx, m);
        long long s2 = solve(l, r, 2 * x + 1, m + 1, rx);
        return merge(s1, s2);
    }
};


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vi v(n);
	for (auto &e : v) {
		cin >> e;
	}
	// using the difference array.
	vi diff(n);
	diff[0] = v[0];
	for (int i = 1; i < n; i++) {
		diff[i] = v[i] - v[i - 1];
	}
	segmentTree st;
	st.build(diff);
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int a, b, u;
			cin >> a >> b >> u;
			st.set(a - 1, u);
			if (b != n) st.set(b, -u);
		}
		else {
			int k;
			cin >> k;
			cout << st.solve(0, k - 1) << "\n";
		}
	}
	return 0;
}