#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	vector<string> ans;
	sort(all(s));
	do {
		ans.push_back(s);
	} while (next_permutation(all(s)));
	cout << ans.size() << "\n";
	for (string &s : ans) cout << s << "\n";
	return 0;
}