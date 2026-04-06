#include <iostream>
#include <vector>

using namespace std;

/**
 * f(a, m) = (a^2 + a) % m
 * Using long long for intermediate calculation to prevent overflow
 */
int f(long long a, int m) {
    return (a * a + a) % m;
}

// Global or static array to handle the large constraint of M
// Using -1 to indicate the value hasn't been seen yet
int last_seen[20000005];

void solve_test(int t) {
    int N, M;
    long long K;
    if (!(cin >> N >> M >> K)) return;

    // Reset the tracking array for each test case up to M
    for (int i = 0; i <= M; ++i) last_seen[i] = -1;

    int a = N % M;
    long long iterations_done = 0;

    while (iterations_done < K) {
        // If we've seen this value of 'a' before, we found a cycle
        if (last_seen[a] != -1) {
            long long cycle_start = last_seen[a];
            long long cycle_len = iterations_done - cycle_start;
            
            // Calculate remaining steps after skipping cycles
            long long remaining_k = (K - iterations_done) % cycle_len;
            
            // Perform the remaining few steps
            for (int i = 0; i < remaining_k; ++i) {
                a = f(a, M);
            }
            break; 
        }

        // Record the first time we see this value and move to next
        last_seen[a] = iterations_done;
        a = f(a, M);
        iterations_done++;
    }

    cout << "Case #" << t << ": " << a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    for (int i = 1; i <= T; ++i) {
        solve_test(i);
    }
    return 0;
}