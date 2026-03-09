#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int A, B;
    // Reading the two known sides
    if (cin >> A >> B) {
        // Calculate the range bounds
        int lower_bound = abs(A - B);
        int upper_bound = A + B;
        
        // The number of integers C such that lower_bound < C < upper_bound
        // Calculation: (upper_bound - 1) - (lower_bound + 1) + 1
        int count = upper_bound - lower_bound - 1;
        
        // Ensure we don't print a negative number (though impossible with A, B >= 1)
        if (count < 0) count = 0;
        
        cout << count << endl;
    }
    
    return 0;
}