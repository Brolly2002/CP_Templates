class DSU {
 private : 
        vector<int> parent,size;
    public :
        DSU(int n){
            for(int i = 0; i <= n; i ++){
                parent.push_back(i); size.push_back(1);
            }
        }
        
        int Find(int node){
            if(parent[node] == node) return node;
            return parent[node] = Find(parent[node]);
        }
        
        void Merge(int u, int v){
            int pu = Find(u);
            int pv = Find(v);
            if(pu == pv) return; 
            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
        
        int compsize(int u){
            return size[u];
        }
};