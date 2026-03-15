#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> lines;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int a_count = s.size() - 1;

        if (a_count % 2 == 1) {
            a_count--;
        }

        if (a_count == 0) {
            a_count = 2;
        }

        string new_line = "b" + string(a_count, 'a');
        lines.push_back(new_line);
    }

    int max_len = 0;
    for (auto &s : lines) {
        max_len = max(max_len, (int)s.size());
    }

    for (auto &s : lines) {
        int spaces = (max_len - s.size()) / 2;
        cout << string(spaces, ' ') << s << "\n";
    }

    return 0;
}