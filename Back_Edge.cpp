vector <vector<int>> _graph, _tree;
vector <bool> mark;
vector <int> dp, depth;
 
void buildTree (int u) {
    mark[u] = true;
    for (auto &v : _graph[u]) {
        if (!mark[v]) {
            _tree[u].push_back(v);
            _tree[v].push_back(u);
            buildTree(v);
        }
    }
}
 
void dfs (int u) {
    mark[u] = true;
    for (auto &v : _tree[u]) {
        if (mark[v]) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
    dp[u] = depth[u];
    for (auto &v : _graph[u]) {
        amin(dp[u], min(dp[v], depth[v]));
    }
}
