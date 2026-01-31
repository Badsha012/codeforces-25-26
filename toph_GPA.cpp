#include <iostream>
#include <vector>
#include <iomanip> // Required for fixed and setprecision

using namespace std;

void solve(int caseNum) {
    int N;
    if (!(cin >> N)) return;

    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        double p;
        cin >> p;
        sum += p;
    }

    double gpa = sum / N;

    // Output formatting: Case x: y.yyy
    cout << "Case " << caseNum << ": " << fixed << setprecision(3) << gpa << endl;
}

int main() {
    int T;
    if (!(cin >> T)) return 0;

    for (int i = 1; i <= T; ++i) {
        solve(i);
    }

    return 0;
}