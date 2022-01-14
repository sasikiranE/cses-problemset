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
    int curr = 1;
    int best = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            curr++;
            best = max(curr, best);
        }
        else curr = 1;
    }
    cout << best << "\n";
    return 0;
}