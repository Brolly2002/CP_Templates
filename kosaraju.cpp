vector <vector<int>> Kosaraju(vector <vector<int>> &graph, int n) {
    vector <int> order;
    vector <bool> vis(n + 1);
    vector <vector<int>> comps;
    
    auto dfs = [&](const auto &go, int u) -> void {
        vis[u] = true;
        for(auto &v : graph[u]) {
            if(vis[v]) continue;
            go(go, v);
        }
        order.push_back(u);
    };

    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) dfs(dfs, i);
    }
    vector <vector<int>> transpose(n + 1);
    for(int i = 1; i <= n; i ++) {
        for(auto &e : graph[i]) transpose[e].push_back(i);
    }
    for(int i = 1; i <= n; i ++) vis[i] = 0;

    auto getscc = [&](const auto &go, int u, vector <int> &cur) -> void {
        vis[u] = true;
        cur.push_back(u);
        for(auto &v : transpose[u]) {
            if(vis[v]) continue;
            go(go, v, cur);
        }
    };

    while(order.size()) {
        int node = order.back(); order.pop_back();
        if(vis[node]) continue;
        vector <int> cur;
        getscc(getscc, node, cur);
        comps.push_back(cur);
    }
    return comps;
}