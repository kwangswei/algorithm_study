#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int bestSchedule(int N, int K, vector<int> workingDays) {
    sort(workingDays.begin(), workingDays.end());
    int best = N;

    for (int start_day_idx = -1, end_day_idx = 0; start_day_idx < (int)workingDays.size(); ++start_day_idx) {
        int end_day = K + (start_day_idx == -1 ? 0 : workingDays[start_day_idx]);

        if (end_day > N)
            break;

        while (end_day_idx < workingDays.size() && workingDays[end_day_idx] <= end_day)
            end_day_idx++;

        best = min(best, end_day_idx - start_day_idx - 1);
    }

    return best;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        int N, K;
        cin >> N >> K;
        int num_of_working_days;
        cin >> num_of_working_days;

        vector<int> working_days(num_of_working_days);
        for (int i = 0; i < num_of_working_days; ++i) {
            cin >> working_days[i];
        }

        cout << bestSchedule(N, K, working_days) << endl;

    }
    return 0;
}
