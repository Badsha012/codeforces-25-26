#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
 
long long mod_pow(long long a, long long b, long long m) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
long long mod_inv(long long a, long long m) {
    return mod_pow(a, m - 2, m);
}
 
int main() {
    long long N, K;
    cin >> N >> K;
    
    // Total length of T
    long long lenT = N * K;
    
    // Total substrings = lenT * (lenT + 1) / 2
    long long total_subs = lenT * (lenT + 1) / 2 % MOD;
    
    // All unique substrings in T
    // For periodic string S^K: |S| * |S| + |S| * (|S| - 1) + ... + |S| * 1
    long long unique_subs = N * (N + 1) / 2 % MOD;
    
    // Substrings with all unique chars = sum of C(n,k) for k=1 to n
    long long sum_fact = 0;
    long long fact = 1;
    for (long long i = 1; i <= min(N, 26LL); i++) {
        fact = fact * i % MOD;
        sum_fact = (sum_fact + fact) % MOD;
    }
    
    // Unique substrings with all unique chars
    long long unique_allunique = sum_fact;
    
    // Bad substrings = unique_allunique
    long long bad_subs = unique_allunique;
    
    // Good substrings = total_unique - bad
    long long good_subs = (unique_subs - bad_subs + MOD) % MOD;
    
    cout << good_subs << endl;
    
    return 0;
}