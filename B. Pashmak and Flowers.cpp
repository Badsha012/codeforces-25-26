#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> b(n);
    long long min_val = 2e9, max_val = -1;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] < min_val) min_val = b[i];
        if (b[i] > max_val) max_val = b[i];
    }

    long long diff = max_val - min_val;
    long long count_min = 0, count_max = 0;

    
    
    for (int i = 0; i < n; i++) {
        if (b[i] == min_val) count_min++;
        if (b[i] == max_val) count_max++;
    }

    long long ways = 0;
    if (min_val == max_val) {
        ways = (long long)n * (n - 1) / 2;
    } else {
        
        ways = count_min * count_max;
    }

    cout << diff << " " << ways << endl;

    return 0;
}