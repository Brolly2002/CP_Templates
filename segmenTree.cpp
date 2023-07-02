template <typename T , class F = function<T(const T&, const T&)>>
class Segtree {
    public :
        int n;
        vector<T> seg;
        vector<T> v;
        F func;
 
        Segtree(const vector<T> &a, const F& f) : func(f) {
            n = a.size();
            v.resize(n);
            seg.resize(4 * n + 5);
            v = a;
        }
 
        void build(int d, int s, int e) {
            if(s == e) {
                seg[d] = v[s]; return;
            }
            int mid = (s + e) >> 1;
            build(2 * d + 1, s, mid);
            build(2 * d + 2, mid + 1, e);
            seg[d] = func(seg[2 * d + 1], seg[2 * d + 2]);
 
        }
 
        void update(int d, int s, int e, int I, T val) {
            if(s == e) {
                seg[d] = val; return;
            }
            int mid = (s + e) >> 1;
            if(I <= mid) update(2 * d + 1, s, mid, I, val);
            else update(2 * d + 2, mid + 1, e, I, val);
            seg[d] = func(seg[2 * d + 1], seg[2 * d + 2]);
 
        }
        
        void Update(int I, T val) {
            return update(0, 0, n - 1, I, val);
        }
 
         
        T query(int d, int  s, int e, int L, int R, T ret) {
            // no overlap
            // ret = 0 :: sum query
            // ret = 1E18 :: min query
            // ret = -1E18 :: max query
            if(R < s || e < L) return ret;
            // complete overlap
            if(s >= L && e <= R) return seg[d];
            // partial overlap
            int mid = (s + e) >> 1;
            T Left = query(2 * d + 1, s, mid, L, R, ret);
            T Right = query(2 * d + 2, mid + 1, e, L, R, ret);
            return func(Left, Right);
        }
        
        T Query(int L, int R, T ret) {
            return query(0, 0, n - 1, L, R, ret);
        }
};