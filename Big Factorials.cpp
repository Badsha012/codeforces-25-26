#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    long long fact = 1;
    bool large = false;

    for (int i = 1; i <= N; i++) {
        fact *= i;
        if (fact >= 10000) {
            large = true;
            fact %= 10000;
        }
    }

    // Check if the actual value was ever 4 digits or more
    if (large || fact >= 1000) {
        // We need to print exactly 4 digits, including leading zeros if necessary
        // Example: if fact is 800, we print 0800
        printf("%04lld\n", fact);
    } else {
        // Naturally small factorial, print as is
        printf("%lld\n", fact);
    }

    return 0;
}