#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {

        // leading spaces (to center)
        for (int s = 1; s <= N - i; s++) {
            cout << " ";
        }

        // print asterisks with space between them
        for (int j = 1; j <= i; j++) {
            cout << "*";
            if (j < i) {
                cout << " "; // no space after last *
            }
        }

        cout << endl;
    }

    return 0;
}
