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
	sort(all(v));
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (v[i] != v[i - 1]) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}