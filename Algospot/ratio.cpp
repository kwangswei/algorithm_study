#include <iostream>
#include <cmath>

using namespace std;

long long solve(long long N, long long M, int target);

int main() {
    int T;
    cin >> T;

    while (T-->0) {
        long long N, M;
        cin >> N >> M;

        int target_ratio = M*100 / N  + 1;

        if (target_ratio >= 100)
            cout << -1 << endl;
        else
            cout << solve(N, M, target_ratio) << endl;
    }
    return 0;
}

long long solve(long long N, long long M, int target) {
    long long lower = 0;
    long long upper = 2000000000;

    while (lower + 1 < upper) {
        long long mid = (lower + upper) / 2;

        int ratio = 100*(M+mid) / (N+mid);

        if (ratio < target) {
            lower = mid;
        }
        else if (ratio >= target) {
            upper = mid;
        }
    }

    return upper;
}
