template <typename T> 
class Nearest {
    public :
        vector<T> ngl, ngr, nsl, nsr;
        vector<T> v;
        int n;

        Nearest(vector<T> &a) {
            n = a.size();  v.resize(n);
            ngl.resize(n); ngr.resize(n); nsr.resize(n); nsl.resize(n);
            for(auto &x : ngr) x = -1;
            for(auto &x : ngl) x = -1;
            for(auto &x : nsl) x = -1;
            for(auto &x : nsr) x = -1;
            v = a;
        }

        void greaterL() {
            vector<T> temp; temp.push_back(0);
            for(int i = 1; i < n; i ++) {
                if(temp.size()) {
                    while(temp.size() && v[temp.back()] <= v[i]) temp.pop_back();
                    if(temp.size()) ngl[i] = temp.back();
                }
                temp.push_back(i);
            }
        }

        void smallerL() {
            vector<T> temp; temp.push_back(0);
            for(int i = 1; i < n; i ++) {
                if(temp.size()) {
                    while(temp.size() && v[temp.back()] >= v[i]) temp.pop_back();
                    if(temp.size()) nsl[i] = temp.back();
                }
                temp.push_back(i);
            }
        }

        void greaterR() {
            vector<T> temp; temp.push_back(n - 1);
            for(int i = n - 2; i >= 0; i --) {
                if(temp.size()) {
                    while(temp.size() && v[temp.back()] <= v[i]) temp.pop_back();
                    if(temp.size()) ngr[i] = temp.back();
                }
                temp.push_back(i);
            }
        }

        void smallerR() {
            vector<T> temp; temp.push_back(n - 1);
            for(int i = n - 2; i >= 0; i --) {
                if(temp.size()) {
                    while(temp.size() && v[temp.back()] >= v[i]) temp.pop_back();
                    if(temp.size()) nsr[i] = temp.back();
                }
                temp.push_back(i);
            }
        }
};
