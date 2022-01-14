#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string s;
	cin >> s;
	int n = s.size();
	vi v(200, 0);
	for (int i = 0; i < n; i++) {
		v[s[i]]++;
	}
	int odd_count = 0, even_count = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (v[i] == 0) continue;
		if (v[i] % 2 == 0) even_count++;
		else odd_count++;
	}
	if (n % 2 == 0) {
		if (odd_count > 0) cout << "NO SOLUTION" << "\n";
		else {
			string ans(n, '$');
			int start = 0, end = n - 1;
			for (int i = 'A'; i <= 'Z'; i++) {
				if (v[i] == 0) continue;
				int k = v[i];
				while (true) {
					if (k == 0) break;
					ans[start++] = (char) i;
					ans[end--] = (char) i;
					k -= 2;
				}
			}
			cout << ans << "\n";
		}
	}
	else {
		if (odd_count > 1 || odd_count == 0) cout << "NO SOLUTION" << "\n";
		else {
			string ans(n, '$');
			char wanted = '$';
			int start = 0, end = n - 1;
			for (int i = 'A'; i <= 'Z'; i++) {
				if (v[i] == 0) continue;
				int k = v[i];
				if (k % 2 == 1) {
					wanted = (char) i;
					k--;
				}
				while (true) {
					if (k == 0) break;
					ans[start++] = (char) i;
					ans[end--] = (char) i;
					k -= 2;
				}
			}
			ans[start] = wanted;
			cout << ans << "\n";
		}
	}
	return 0;
}