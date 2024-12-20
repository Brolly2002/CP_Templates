struct flowEdge {
    int u, v;
    long long capacity = 0, flow = 0;
    flowEdge (int _u, int _v, long long cap) : v(_v), u(_u), capacity(cap) {}
};


struct dinic {

    const long long infiniteFlow = 1E18; // change based on the problem statement
    vector <flowEdge> edges;
    vector <vector<int>> _graph;
    int numberOfNodes, edgeId = 0;
    int source, sink;
    vector <int> level, ptr;
    queue <int> q;

    dinic (int n, int s, int t) : numberOfNodes(n), source(s), sink(t) {
        _graph.resize(n + 1);
        level.resize(n + 1);
        ptr.resize(n + 1);
    }

    void addEdge (int to, int from, long long cap, long long cap2) {
        flowEdge u_to_v = flowEdge(to, from, cap);
        flowEdge v_to_u = flowEdge(from, to, cap2);
        edges.push_back(u_to_v);
        edges.push_back(v_to_u);
        _graph[to].push_back(edgeId);
        _graph[from].push_back(edgeId ^ 1);
        edgeId += 2;
    }

    // Virtually building a layered network by assigning levels
    bool layeredNetwork () {
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int cur_edgeID : _graph[node]) {
                if (edges[cur_edgeID].capacity - edges[cur_edgeID].flow < 1) continue;
                else if (level[edges[cur_edgeID].v] >= 0) continue;
                level[edges[cur_edgeID].v] = level[node] + 1;
                q.push(edges[cur_edgeID].v);
            }
        }
        return level[sink] >= 0;
    }

    // Find an augementing path having residual capcity > 0
    long long findAugementingPath (int node, long long minCapacity) {
        if (minCapacity == 0) return 0LL;
        else if (node == sink) return minCapacity;
        while (ptr[node] < (int) _graph[node].size()) {
            int id = _graph[node][ptr[node]];
            int adjVertex = edges[id].v;
            // This current adjVertex has no augumenting path further, Hence we'll increment the pointer so that it can't be considered again
            // in our current layered network
            if ((level[node] + 1) != level[adjVertex] or edges[id].capacity - edges[id].flow < 1) {
                ptr[node] ++;
                continue;
            }
            long long getMinCapacity = findAugementingPath(adjVertex, min(minCapacity, edges[id].capacity - edges[id].flow));
            // same as the comment mentioned above
            if (getMinCapacity == 0) {
                ptr[node] ++;
                continue;
            }
            edges[id].flow += getMinCapacity;
            edges[id ^ 1].flow -= getMinCapacity;
            return getMinCapacity;
        }
        return 0LL;
    }

    long long getMaxFlow () {
        long long _flow = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[source] = 0;
            q.push(source);
            if (!layeredNetwork()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long curCapacity = findAugementingPath(source, infiniteFlow)) {
                _flow += curCapacity;
            }
        }
        return _flow;
    }

    vector <array<int, 2>> minCutEdges () {
        vector <int> reachFromSource(numberOfNodes + 1);
        vector <array<int, 2>> ans;
        q.push(source);
        reachFromSource[source] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int cur_edgeID : _graph[node]) {
                if (edges[cur_edgeID].capacity - edges[cur_edgeID].flow > 0 and !reachFromSource[edges[cur_edgeID].v]) {
                    reachFromSource[edges[cur_edgeID].v] = 1;
                    q.push(edges[cur_edgeID].v); 
                }
            }
        }
        
        for (int i = 0; i < edges.size(); i += 2) {
            if (reachFromSource[edges[i].u] and !reachFromSource[edges[i].v]) {
                ans.push_back({edges[i].u, edges[i].v});
            }
        }
        return ans;
    }

};
