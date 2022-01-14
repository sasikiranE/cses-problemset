#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pi> vp;
    for (int i = 0; i < n; i++) {
    	int a, b;
    	cin >> a >> b;
    	vp.push_back(make_pair(a, 1));
    	vp.push_back(make_pair(b, -1));
    }
    sort(all(vp));
    int curr = 0;
    int best = 0;
    for (auto &p : vp) {
    	curr += p.second;
    	best = max(best, curr);
    }
    cout << best << "\n";
    return 0;
}