class Matching {
    public :
        vector <int> LPS, Z, PAL;
        int n;

        Matching(int _n) : n(_n) {
            LPS.resize(n);  Z.resize(n), PAL.resize(n);
            for(int i = 0; i < n; i ++) LPS[i] = Z[i] = PAL[i] = 0;
        }

        void kmp(string s) {
            int i = 1, len = 0;
            while(i < n) {
                if(s[i] == s[len]) {
                    len ++;
                    LPS[i] = len;
                    i ++;
                }
                else {
                    if(len > 0) len = LPS[len - 1];
                    else LPS[i] = 0, i ++;
                }
            }
        }

        void Z_(string s) {
            int L = 0, R = 0;
            for(int i = 1; i < s.size(); i ++) {
                if(i <= R) Z[i] = min(R - i + 1, Z[i - L]);
                while(s[Z[i]] == s[i + Z[i]]) Z[i] ++;
                if(i + Z[i] - 1 > R) L = i, R = i + Z[i] - 1;
            }
        }


        void Manacher(string s) {
            int r = 0, c = 0;
            for(int i = 1; i < n; i ++) {
                int mirror = c - (i - c);
                if(i < r) PAL[i] = min(PAL[mirror], r - i);
                while(s[i + PAL[i] + 1] == s[i - PAL[i] - 1]) PAL[i] ++;
                if(i + PAL[i] > r) c = i, r = i + PAL[i];
            }
        }
};