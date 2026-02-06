#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    // Sort b to know what the target array should look like
    sort(b.begin(), b.end());

    int L = -1, R = -1;

    // Find the first index where a and b differ
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            L = i;
            break;
        }
    }

    // If no difference is found, the array is already sorted
    if (L == -1) {
        cout << "yes" << endl;
        cout << "1 1" << endl;
        return 0;
    }

    // Find the last index where a and b differ
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            R = i;
            break;
        }
    }

    // Reverse the identified segment in the original array
    reverse(a.begin() + L, a.begin() + R + 1);

    // Check if reversing that specific segment sorted the array
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "yes" << endl;
        // Convert 0-based indexing to 1-based indexing for output
        cout << L + 1 << " " << R + 1 << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}