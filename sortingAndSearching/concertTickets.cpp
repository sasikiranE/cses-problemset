#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	multiset<int, greater<int>> st;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		auto it = st.lower_bound(k);
		if (it == st.end()) {
			cout << "-1" << "\n";
		}
		else {
			cout << *it << "\n";
			st.erase(it);
		}
	}
	return 0;
}