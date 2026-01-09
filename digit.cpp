#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;

    while (N > 0) {
        int digit = N % 10;   // last digit
        if (digit % 2 != 0) { // odd check
            count++;
        }
        N /= 10;              // remove last digit
    }

    cout << count << endl;

    return 0;
}
