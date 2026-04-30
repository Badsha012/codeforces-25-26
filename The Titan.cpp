#include <iostream>

using namespace std;

int main() {
    int N;
    
    // Read the input N
    if (cin >> N) {
        
        long long result = (1LL * N * (N + 1) * (2 * N + 1)) / 6;
        
        cout << result << endl;
    }
    
    return 0;
}