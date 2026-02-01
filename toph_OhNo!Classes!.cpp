#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end;
};

// Comparator to sort intervals by start time
bool compareIntervals(Interval i1, Interval i2) {
    return i1.start < i2.start;
}

void solve() {
    vector<Interval> intervals(3);
    for (int i = 0; i < 3; ++i) {
        int u, v;
        cin >> u >> v;
        // Ensure start is less than or equal to end
        intervals[i].start = min(u, v);
        intervals[i].end = max(u, v);
    }

    // Sort intervals based on start time
    sort(intervals.begin(), intervals.end(), compareIntervals);

    vector<Interval> merged;
    if (3 > 0) {
        merged.push_back(intervals[0]);
    }

    for (int i = 1; i < 3; ++i) {
        Interval& last = merged.back();
        // If current interval overlaps with the last merged one
        if (intervals[i].start <= last.end) {
            last.end = max(last.end, intervals[i].end);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    long long total_time = 0;
    for (const auto& interval : merged) {
        // +1 because the intervals are inclusive (e.g., 1 to 2 is 2 seconds)
        total_time += (interval.end - interval.start + 1);
    }

    cout << total_time << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}