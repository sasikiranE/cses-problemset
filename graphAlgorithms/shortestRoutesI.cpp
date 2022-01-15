#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;
const long long inf = 1e18;


// Using single source shortest path algo -> Dijkstra's algo.

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pll> graph[n + 1];
    for (int i = 0; i < m; i++) {
    	ll u, v, w;
    	cin >> u >> v >> w;
    	graph[u].push_back(make_pair(v, w));
    }

    vector<bool> processed(n + 1, false);
    vector<ll> dis(n + 1, inf);

    dis[1] = 0;
    priority_queue<pll, vector<pll>> q;
    q.push(make_pair(-dis[1], 1));

    while (!q.empty()) {
    	int node = q.top().second;
    	q.pop();
    	if (processed[node]) continue;
    	processed[node] = true;
    	for (auto &p : graph[node]) {
    		ll v = p.first, w = p.second;
    		if (dis[node] + w < dis[v]) {
    			dis[v] = dis[node] + w;
    			q.push(make_pair(-dis[v], v));
    		}
    	}
    }

    for (int i = 1; i <= n; i++) {
    	cout << dis[i] << " ";
    }
    cout << "\n";
    return 0;
}