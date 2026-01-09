#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;

    double sum = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    double avg = sum / N;

    cout << fixed << setprecision(2) << avg << endl;

    return 0;
}
