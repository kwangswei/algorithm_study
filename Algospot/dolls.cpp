#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>& origin, int m) {
    vector<int> counts = origin;

    sort(counts.begin(), counts.end());

    int total_sub = 0;
    for (int i = 0; i < counts.size(); ++i) {
        int can = counts[i] - total_sub;
        int cnt = counts.size() - i;

        if (can * cnt <= m) {
            m -= can*cnt;
            total_sub += can;
        }
        else {
            total_sub += m / cnt;
            m -= m/cnt * cnt;
            break;
        }
    }

    for (int i = 0; i < origin.size(); ++i) {
        if (origin[i] <= total_sub)
            cout << origin[i] << " ";
        else if (m-- > 0)
            cout << total_sub + 1 << " ";
        else 
            cout << total_sub << " ";
    } 

    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;

        cin >> N >> M;
        vector<int> counts(N);
        for (int i = 0; i < N; ++i)
            cin >> counts[i];

        solve(counts, M);
    }
}


