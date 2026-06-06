#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Case 1: Same vertical line (x-coordinates match)
    if (x1 == x2) {
        int side = abs(y1 - y2);
        cout << x1 + side << " " << y1 << " " << x2 + side << " " << y2 << "\n";
    }
    // Case 2: Same horizontal line (y-coordinates match)
    else if (y1 == y2) {
        int side = abs(x1 - x2);
        cout << x1 << " " << y1 + side << " " << x2 << " " << y2 + side << "\n";
    }
    // Case 3: Diagonal line (dx must equal dy for a valid square)
    else if (abs(x1 - x2) == abs(y1 - y2)) {
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << "\n";
    }
    // Case 4: Impossible to form a square parallel to the axes
    else {
        cout << -1 << "\n";
    }

    return 0;
}
