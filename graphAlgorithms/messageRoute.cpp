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
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }
    vi p(n + 1);
    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
    	int node = q.front();
    	q.pop();
    	for (auto &nei : graph[node]) {
    		if (vis[nei]) continue;
    		p[nei] = node;
    		q.push(nei);
    		vis[nei] = true;
    	}
    }
    if (vis[n]) {
    	vi path;
    	for (int i = n; i != 0; i = p[i]) {
    		path.push_back(i);
    	}
    	reverse(all(path));
    	cout << path.size() << "\n";
    	for (auto &e : path) {
    		cout << e << " ";
    	}
    	cout << "\n";
    }
    else {
    	cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}