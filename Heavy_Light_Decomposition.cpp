#include <bits/stdc++.h>
using namespace std;
 
template <typename T>
struct Segtree {
	static constexpr T unit = 0;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Segtree (int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void Update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T Query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
 
template <typename T>
class binary_lifting {
    public :
        int n;
        vector<vector<T>> dp;
        vector<T> lev;
        vector<vector<T>> Tree;
 
        binary_lifting(const vector<vector<T>>& tree) {
            n = static_cast<int>(tree.size());
            dp.resize(n);   lev.resize(n);  Tree.resize(n);
            for(int i = 0; i < n; i ++) {
                dp[i].resize(19);
                for(auto &v : tree[i]) {
                    Tree[i].push_back(v);
                }
            }
        }
 
        void Levels(T u, T p) {
            for(auto &v : Tree[u]) {
                if(v == p) continue;
                lev[v] = lev[u] + 1;
                Levels(v, u);
            }
        }
 
        void Lift(T u, T p) {
            dp[u][0] = p;
            for(int i = 1; i <= 18; i ++) {
                if(dp[u][i - 1]) dp[u][i] = dp[dp[u][i - 1]][i - 1];
                else dp[u][i] = 0;
            }
            for(auto &v : Tree[u]) {
                if(v == p) continue;
                Lift(v, u);
            }
        }
 
        T get(T u, T jump) {
            for(int i = 18; i >= 0; i --) {
                if(jump == 0 || u == 0) break;
                if(jump >= (1 << i)) {
                    jump -= (1 << i);
                    u = dp[u][i];
                }
            }
            return u;
        }
 
        T Query(T u, T v) {
            if(lev[u] < lev[v]) swap(u, v);
            u = get(u, lev[u] - lev[v]);
            if(u == v) return u;
            for(int i = 18; i >= 0; i --) {
                if(dp[u][i] != dp[v][i]) {
                    u = dp[u][i];
                    v = dp[v][i];
                }
            }
            return get(u, 1);
        }
 
};
 
int n, q;
vector <int> values, subTree, depth, parent, heavy, path, _index, root;
vector <vector<int>> t;
 
void markHeavyEdges (int u, int p) {
    subTree[u] = 1;
    heavy[u] = -1;
    int mx = 0;
    for (auto &v : t[u]) {
        if (v == p) continue;
        markHeavyEdges(v, u);
        subTree[u] += subTree[v], depth[v] = depth[u] + 1, parent[v] = u;
        if (subTree[v] > mx) {
            mx = subTree[v];
            heavy[u] = v;
        }
    }
} 
 
void tracePath (int u, int p) {
    path.push_back(u);
    if (heavy[u] != -1) tracePath(heavy[u], u);
    for (auto &v : t[u]) {
        if (v == p || v == heavy[u]) continue;
        tracePath(v, u);
    }
}
 
void workOnPath () {
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && heavy[path[j - 1]] == path[j]) j ++;
        // i to j - 1 tk k bnde ek he heavy path mein hone jism root 'i' hogi us heavy path k liye
        for (int k = i; k < j; k ++) {
            root[path[k]] = path[i];
        }
        i = j;
    }
    for (int i = 0; i < n; i ++) _index[path[i]] = i;
}
 
 
 
void Solution()
{
    
    
    cin >> n >> q;
    root = values = subTree = depth = parent = heavy = _index = vector <int> (n + 1);
    path.clear();
    t = vector <vector<int>> (n + 1);
    for (int i = 1; i <= n; i ++) cin >> values[i];
    for (int i = 1; i <= n - 1; i ++) {
        int u, v; cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
 
    binary_lifting <int> ancestor(t);
    ancestor.Levels(1, 0); ancestor.Lift(1, 0);
 
    markHeavyEdges(1, 0);
    tracePath(1, 0);
    workOnPath();
 
 
    Segtree <int> seg(n + 1);
    for (int i = 0; i < n; i ++) seg.Update(i, values[path[i]]);
    
 
    auto query = [&](int u, int lca) -> int {
        int ans = 0;
        while (true) {
            // not in same heavy path
            if (root[u] != root[lca]) {
                int l = _index[root[u]], r = _index[u];
                amax(ans, seg.Query(l, r + 1)); 
                u = parent[root[u]];
            }
            else {
                int l = _index[lca], r = _index[u];
                amax(ans, seg.Query(l, r + 1));
                break;
            }
        }
        return ans;
    };
    
 
    while (q --) {
        int type; cin >> type;
        if (type == 1) {
            int node, val; cin >> node >> val;
            seg.Update(_index[node], val);
        }
        else {
            int u, v; cin >> u >> v;
            int lca = ancestor.Query(u, v);
            cout << max(query(u, lca), query(v, lca)) << ' ';
        }
    }
 
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int Test_case = 1;  // cin >> Test_case;
    
    while(Test_case --) Solution();
    
}
