#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi v(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> v[i];
    }
    vector<ll> preSum(n + 1);
    for (int i = 1; i <= n; i++) {
    	preSum[i] = v[i] + preSum[i - 1];
    }
    while (m--) {
    	int a, b;
    	cin >> a >> b;
    	cout << preSum[b] - preSum[a - 1] << "\n";
    }
    return 0;
}