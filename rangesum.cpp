template <typename T>
class range_sum {
    public :
        int n;
        vector <T> seg;
        vector <T> v;
        vector <T> lazy;
        vector <bool> mark;

        range_sum(const vector<T> &a) {
            n = a.size();
            v.resize(n);
            seg.resize(4 * n + 5);
            lazy.resize(4 * n + 5);
            mark.resize(4 * n + 5);
            for(int i = 0; i < 4 * n + 5; i ++) lazy[i] = seg[i] = 0, mark[i] = false;
            v = a;
        }

        void build(int d, int s, int e) {
            if(s == e) {
                seg[d] = v[s];  return;
            }
            int mid = (s + e) >> 1;
            build(2 * d + 1, s, mid);
            build(2 * d + 2, mid + 1, e);
            seg[d] = seg[2 * d + 1] + seg[2 * d + 2];
        }

        void propagate(int d, int s, int e, T val) {
            if(!mark[d]) return;
            seg[d] = (e - s + 1) * val; mark[d] = false; lazy[d] = 0;
            if(s != e) {
                lazy[2 * d + 1] = val;
                mark[2 * d + 1] = true;
                lazy[2 * d + 2] = val;
                mark[2 * d + 2] = true;
            }
            return;
        }

        // note : jb update increment vala hoga to sb = ko += se replace kr dena
        void update(int d, int s, int e, int l, int r, T val) {
            propagate(d, s, e, lazy[d]);
            if(e < l || s > r) return; 
            if(s >= l && e <= r) { 
                seg[d] = (e - s + 1) * val;
                if(s != e) {
                    mark[2 * d + 1] = true;
                    lazy[2 * d + 1] = val;
                    mark[2 * d + 2] = true;
                    lazy[2 * d + 2] = val;
                }
                mark[d] = false;
                lazy[d] = 0;
                return;
            }
            int mid = (s + e) >> 1;
            update(2 * d + 1, s, mid, l, r, val);
            update(2 * d + 2, mid + 1, e, l, r, val);
            seg[d] = seg[2 * d + 1] + seg[2 * d + 2];
        }

        T query(int d, int s, int e, int l, int r, T ret) {
            propagate(d, s, e, lazy[d]);
            if(e < l || s > r) return ret; 
            if(s >= l && e <= r) return seg[d];
            int mid = (s + e) >> 1;
            T left = query(2 * d + 1, s, mid, l, r, ret);
            T right = query(2 * d + 2, mid + 1, e, l, r, ret);
            return left + right;
        }

        void Update(int l, int r, T val) {
            update(0, 0, n - 1, l, r, val);
        }

        T Query(int l, int r, T ret) {
            return query(0, 0, n - 1, l, r, ret);
        }

};
