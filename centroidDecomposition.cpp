int n; 
vector <vector<int>> t, centroid_tree;
vector <int> mark, treesize;

void init() {
    cin >> n;
    t = vector <vector<int>> (n + 1);
    centroid_tree = vector <vector<int>> (n + 1);
    mark = vector <int> (n + 1);
    treesize = vector <int> (n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int u, v; cin >> u >> v;
        t[u].push_back(v); t[v].push_back(u);
    }
}

int find_size(int u, int p) {
    if(mark[u]) return 0;
    treesize[u] = 1;
    for(auto &v : t[u]) {
        if(v != p) treesize[u] += find_size(v, u);
    }
    return treesize[u];
}

int find_centroid(int u, int p, int m) {
    for(auto &v : t[u]) {
        if(v != p) {
            if(!mark[v] && treesize[v] > m / 2) return find_centroid(v, u, m);
        }
    }
    return u;
}

void centroid_decomposition(int u, int p) {
    find_size(u, p);
    int center = find_centroid(u, p, treesize[u]);
    mark[center] = 1;
    centroid_tree[p].push_back(center);
    for(auto &v : t[center]) {
        if(!mark[v]) centroid_decomposition(v, center);
    }
}
