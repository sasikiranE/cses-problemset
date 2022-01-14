#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

struct segmentTree {
    int size;
    vector<int> tree;
    int NEUTRAL_ELEMENT= -1;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, NEUTRAL_ELEMENT);
    }

    int merge(int a, int b) {
        return max(a, b);
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
            tree[x] -= val;
            return;
        }
        int m = lx + (rx - lx) / 2;
        if (i <= m) set(i, val, 2 * x, lx, m);
        else set(i, val, 2 * x + 1, m + 1, rx);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    int solve(int l, int r) {
        return solve(l, r, 1, 0, size - 1);
    }

    int solve(int l, int r, int x, int lx, int rx) {
        if (lx > r or rx < l) return NEUTRAL_ELEMENT;
        if (lx >= l and rx <= r) return tree[x];
        int m = lx + (rx - lx) / 2;
        int s1 = solve(l, r, 2 * x, lx, m);
        int s2 = solve(l, r, 2 * x + 1, m + 1, rx);
        return merge(s1, s2);
    }

    int find(int val) {
    	return find(val, 1, 0, size - 1);
    }

    int find(int val, int x, int lx, int rx) {
    	if (tree[x] < val) return NEUTRAL_ELEMENT;
    	if (lx == rx) return lx;
    	int m = lx + (rx - lx) / 2;
    	int res = find(val, 2 * x, lx, m);
    	if (res == NEUTRAL_ELEMENT) res = find(val, 2 * x + 1, m + 1, rx);
    	return res;
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
    vi q(m);
    for (auto &e : q) {
    	cin >> e;
    }
    segmentTree st;
    st.build(v);
    for (auto &e : q) {
    	int ans = st.find(e);
    	if (ans != -1) st.set(ans, e);
    	cout << ans + 1 << " ";
    }
    cout << "\n";
    return 0;
}