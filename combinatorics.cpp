const int N = 300005;
long long fact[N], Inv[N], Ninv[N];
 
void compute() {
    // compute inverse of numbers
    Ninv[0] = Ninv[1] = 1;
    for(long long i = 2; i < N; i ++) {
        Ninv[i] = Ninv[Mod % i] * (Mod - Mod / i) % Mod;
    }
    // compute inverse of facts
    Inv[0] = Inv[1] = 1;
    for(long long i = 2; i < N; i ++) {
        Inv[i] = (Ninv[i] * Inv[i - 1]) % Mod;
    }
    // compute factorials
    fact[0] = 1;
    for(long long i = 1; i < N; i ++) {
        fact[i] = (fact[i - 1] * i) % Mod;
    }
}
 
long long NCR(long long N, long long R) {
    long long ans = ((fact[N] * Inv[R]) % Mod * Inv[N - R]) % Mod;
    return ans;
}