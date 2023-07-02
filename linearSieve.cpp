class Linear_Sieve {
    public :
        int n;
        vector <int> factor;
        vector <int> primes;

        Linear_Sieve(int N) {
            n = N;
            factor.resize(n + 1);
        }

        void build() {
            for (i64 i = 2; i <= n; ++ i) {
                if (factor[i] == 0) {
                    factor[i] = i;
                    primes.push_back(i);
                }
                for (i64 j = 0; i * primes[j] <= n; ++ j) {
                    factor[i * primes[j]] = primes[j];
                    if (primes[j] == factor[i]) {
                        break;
                    }
                }
            }
        }
};
