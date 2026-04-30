#include <iostream>

using namespace std;

int main() {
    // We use long long because K, S, and B can be up to 10^9.

    long long K, S, B;

    // Read input: number of kids, Subhashis's shirts, and Bipro's shirts
    if (cin >> K >> S >> B) {
        // Calculate total shirts
        long long totalShirts = S + B;

      
        if (totalShirts >= K) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}