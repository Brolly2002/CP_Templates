#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// member functions :
// 1. order_of_key(k) : number of elements strictly lesser than k
// 2. find_by_order(k) : k-th element in the set
template <class key, class value, class cmp = std::less<key>>
using o_map = __gnu_pbds::tree<key, value, cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

using i64 = long long;
const i64 Mod = 1000000007;
const i64 MOD = 998244353;
const i64 Inf = 1E18;
const int dx[] = {0,  0, 1, -1, -1, -1,  1, 1};
const int dy[] = {1, -1, 0,  0, -1,  1, -1, 1};

//FOR unordered_map<int,int,custom_hash> TO AVOID FALTU TLE'S COZ OF ANTIHASHES.
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};	
    
template <typename T>
T roundup(T a, T b) {
    return(a / b + ((a ^ b) > 0 && a % b));
}

template <typename T>
T choose(T n, T r) {
    if(n < r) return 0LL; 
    T res = 1;
    for(T e = 0 ; e < r ; e ++) {
        res = res * (n - e);
        res = res / (e + 1); 
    }
    return res;
}

template <typename T>
bool expotwo(T n) {
    T val = (n & (n - 1));
    if(val == 0LL) return true; 
    return false;
}

template <typename T>
T modexpo(T b, T e, T mod) {
    T ans = 1;
    while(e) {
        if(e & 1) ans = ((ans % mod) * (b % mod)) % mod;
        b = ((b % mod) * (b % mod)) % mod;
        e >>= 1;
    }
    return ans;
}

template <typename T>
T expo(T b, T e) {
    T ans = 1;
    while(e) {
        if(e & 1) ans = ans * b;
        b = b * b;
        e >>= 1;
    }
    return ans;
}

template <typename T>
bool eprime(T n) {
    if(n < 2) return false;
    for(T e = 2; e * e <= n; e ++) {
        if(n % e == 0) return false;
    }
    return true;
}

template <typename T>
bool eparity(T x, T y) {
    return !((x & 1) ^ (y & 1));
};

template <typename T>
void amax(T& a, T b) { 
    a = max(a, b);
}

template <typename T>
void amin(T& a, T b) {
    a = min(a, b);
}

template <typename T>
void add(T& a, T b, T M) {
    a = ((a % M) + (b % M)) % M;
}

template <typename T>
void mul(T& a, T b, T M) {
    a = ((a % M) * (b % M)) % M;
}

template <typename T>
void sub(T& a, T b, T M) {
    a = (a - b + M) % M;
}

/* ------------------------------------------ lessgo -------------------------------------------------*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


void Solution()
{
    
    

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int Test_case = 1;   cin >> Test_case;
    
    while(Test_case --) Solution();
    
}
