template <typename T>
class Fenwick {

    public :
        vector<T> fenw;
        int n;
        
        Fenwick(int _n) : n(_n) {
            fenw.resize(n + 1);
        }
        
        void Modify(int x, T v) {
            while(x <= n) {
                fenw[x] += v;
                x += (x & (-x));
            }
        }
        
        T Get(int x) {
            T v{};
            while(x > 0) {
                v += fenw[x];
                x -= (x & (-x));
            }
            return v;
        }
        
        T Get_kth(T val) {
            T L = 1, R = n, idx = n;
            while(L <= R) {
                int mid = (L + R) >> 1;
                if(Get(mid) >= val) R = mid - 1, idx = mid;
                else L = mid + 1;
            }
            return idx;
        }
};