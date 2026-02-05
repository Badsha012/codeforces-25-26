#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_VAL = 10000001;
bitset<MAX_VAL> is_prime;

// 1. Precompute primes up to 10^7 using Sieve
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int p = 2; p * p < MAX_VAL; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_VAL; i += p)
                is_prime[i] = 0;
        }
    }
}

// 2. Fenwick Tree (Binary Indexed Tree)
int bit[100005];
int n;

void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    if (!(cin >> n)) return 0;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (is_prime[arr[i]]) {
            update(i, 1); // Treat prime as 1
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            // Handle range sum [x, y]
            cout << query(y) - query(x - 1) << "\n";
        } else {
            int x, val;
            cin >> x >> val;
            // Check if the prime status changed
            bool was_prime = is_prime[arr[x]];
            bool now_prime = is_prime[val];

            if (was_prime && !now_prime) {
                update(x, -1); // Lost a prime
            } else if (!was_prime && now_prime) {
                update(x, 1);  // Gained a prime
            }
            arr[x] = val; // Update the actual value in array
        }
    }

    return 0;
}