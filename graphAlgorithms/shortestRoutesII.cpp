#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;
const long long inf = 1e18;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	// Floyd warshall algorithm.
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>> adj(n + 1, vector<ll>(n + 1));

	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		if (adj[u][v] == 0) {
			adj[u][v] = adj[v][u] = w;
		}
		else {
			adj[u][v] = adj[v][u] = min(adj[u][v], w);
		}
	}

	// creating dis matrix.
	vector<vector<ll>> dis(n + 1, vector<ll>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dis[i][j] = 0;
			}
			else if (adj[i][j]) {
				dis[i][j] = adj[i][j];
			}
			else {
				dis[i][j] = dis[j][i] = inf;
			}
		}
	}

	// applying dp.

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << (dis[u][v] == inf ? -1 : dis[u][v]) << "\n";
	}
	return 0;
}