#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int bestSchedule(int N, int K, vector<int> workingDays) {
    set<int> s(workingDays.begin(), workingDays.end());
    s.insert(0);

    int best = 9999999;

    set<int>::iterator start_day_it = s.begin();
    set<int>::iterator end_day_it = s.begin();
    int dist = 0;
    
    for (; start_day_it != s.end(); ++start_day_it, --dist) {
        int end_day = *start_day_it + K;

        if (end_day > N)
            break;

        while (end_day_it != s.end() && *end_day_it <= end_day) {
            end_day_it++;
            dist++;
        }
        best = min(best, dist - 1);
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
