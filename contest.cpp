#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    
    vector<int> d = {a, b, c};
    sort(d.begin(), d.end());

    int x = d[0], y = d[1];

    int moves = n - 1;
    int result = 0;

    
    result += (moves / 2) * (x + y);

    
    if (moves % 2 == 1) {
        result += x;
    }

    cout << result << endl;
    return 0;
}
