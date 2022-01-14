#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    while (n > 0) {
        ans += (n / 5);
        n /= 5;
    }
    cout << ans << "\n";
    return 0;
}