class two_sat {

    public:

        int n;
        vector <vector<int>> _graph, _revgraph;
        vector <int> order, comp, assign, vis;

        two_sat (int N) {
            n = N;
            _graph = _revgraph = vector <vector<int>> (2 * n);
            comp = vis = vector <int> (2 * n);
            assign = vector <int> (n);
        }
        
        void add_edge (int u, int v) {
            _graph[u].push_back(v);
            _revgraph[v].push_back(u);
        }

        void add_disjunction (int a, bool na, int b, bool nb) {
            // a | b
            if (!na and !nb) {
                add_edge(a + n, b);
                add_edge(b + n, a);
            }
            // ~a | b
            else if (na and !nb) {
                add_edge(a, b);
                add_edge(b + n, a + n);
            }
            // a | ~b
            else if (!na and nb) {
                add_edge(a + n, b + n);
                add_edge(b, a);
            }
            // ~a | ~b
            else {
                add_edge(a, b + n);
                add_edge(b, a + n);
            }
        }

        void dfs (int node) {
            vis[node] = 1;
            for (auto &v : _graph[node]) {
                if (!vis[v]) dfs(v);
            }
            order.push_back(node);
        }

        void revdfs (int node, int counter) {
            vis[node] = 1;
            comp[node] = counter;
            for (auto &v : _revgraph[node]) {
                if (!vis[v]) revdfs(v, counter);
            }
        }

        bool possible() {
            for (int i = 0; i < 2 * n; i ++) {
                if (!vis[i]) dfs(i);
            }
            reverse(order.begin(), order.end());
            for (int i = 0; i < 2 * n; i ++) vis[i] = 0;
            int cnt = 0;
            for (auto &x : order) {
                if (!vis[x]) {
                    revdfs(x, cnt ++);
                }
            }
            for (int i = 0; i < n; i ++) {
                if (comp[i] == comp[i + n]) {
                    return false;
                }
                else if (comp[i] > comp[i + n]) assign[i] = 1;
                else assign[i] = 0;
            }
            return true;
        }

};
