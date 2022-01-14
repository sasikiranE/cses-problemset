#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vi v(n);
	for (auto &e : v) {
		cin >> e;
	}
	ll total = accumulate(all(v), 0LL);
	ll best = total;
	for (int msk = 0; msk < (1 << n); msk++) {
		bitset<20> b(msk);
		ll curr = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] == 1) curr += v[i];
		}
		best = min(best, abs(total - 2 * curr));
	}
	cout << best << "\n";
	return 0;
}