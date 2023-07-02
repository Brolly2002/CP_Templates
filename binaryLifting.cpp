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