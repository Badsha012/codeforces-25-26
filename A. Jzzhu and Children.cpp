#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    int last_child = 1;
    int max_rounds = 0;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;

        // Calculate how many times the child needs to go to the front
        // Equivalent to ceil(a/m)
        int rounds = (a + m - 1) / m;

        // If this child needs more rounds than any previous child, 
        // or the same amount but is further back in line (>=), 
        // they become the new 'last child'.
        if (rounds >= max_rounds) {
            max_rounds = rounds;
            last_child = i;
        }
    }

    cout << last_child << endl;

    return 0;
}