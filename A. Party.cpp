#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // managers[i] stores the manager of employee i+1
    vector<int> managers(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> managers[i];
    }

    int max_depth = 0;

    // For every employee, find how deep they are in the hierarchy
    for (int i = 1; i <= n; ++i) {
        int current_depth = 0;
        int current_emp = i;

        // Traverse up the chain until we reach a root (-1)
        while (current_emp != -1) {
            current_emp = managers[current_emp];
            current_depth++;
        }

        // The answer is the maximum depth found across all employees
        max_depth = max(max_depth, current_depth);
    }

    cout << max_depth << endl;

    return 0;
}