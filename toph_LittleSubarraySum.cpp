#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    // Reading N, start index A, and end index B
    if (!(cin >> n >> a >> b)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long sum = 0;
    // Iterate from A to B (inclusive)
    for (int i = a; i <= b; ++i) {
        sum += arr[i];
    }

    cout << sum << endl;

    return 0;
}