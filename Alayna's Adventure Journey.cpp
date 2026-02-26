#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long max_elephants = -1; 

    for (int i = 0; i < n; i++) {
        long long current_group;
        cin >> current_group;

   
        if (current_group > max_elephants) {
            max_elephants = current_group;
        }
    }


    cout << max_elephants << endl;

    return 0;
}