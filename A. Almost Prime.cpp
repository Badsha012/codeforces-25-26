#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    // Array to store the count of distinct prime factors for each number
    vector<int> prime_counts(n + 1, 0);

    // Sieve-like approach to count distinct prime factors
    for (int i = 2; i <= n; ++i) {
        // If prime_counts[i] is 0, i is a prime number
        if (prime_counts[i] == 0) {
            for (int j = i; j <= n; j += i) {
                prime_counts[j]++;
            }
        }
    }

    // Count how many numbers have exactly 2 distinct prime factors
    int almost_prime_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (prime_counts[i] == 2) {
            almost_prime_count++;
        }
    }

    cout << almost_prime_count << endl;

    return 0;
}