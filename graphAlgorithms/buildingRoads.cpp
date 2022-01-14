#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;

int n, m;
vector<vi> graph;
vector<bool> vis;

void dfs(int node) {
	vis[node] = true;
	for (auto &nei : graph[node]) {
		if (vis[nei]) continue;
		dfs(nei);
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    graph.resize(n + 1, vi());
    vis.resize(n + 1);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }
    vector<pi> roads;
    dfs(1);
    int curr = 1;
    for (int i = 2; i <= n; i++) {
    	if (!vis[i]) {
    		roads.push_back(make_pair(curr, i));
    		dfs(i);
    		curr = i;
    	}
    }
    cout << roads.size() << "\n";
    for (auto &p : roads) {
    	cout << p.first << " " << p.second << "\n";
    }
    return 0;
}