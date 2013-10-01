#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 500;
const int MAX_K = 100;
const int DIVIDER = 1000000007;

int N, K;

int cache[2][MAX_N][MAX_K+1];

void preprocessing() {
    memset(cache, 0, sizeof(cache));
    cache[0][0][0] = cache[0][0][1] = cache[1][0][0] = 1;

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= N; j++) {
            for (int p = 1; p <= K; p++) {
                int include_ith_num = cache[(i-1)%2][(j-i+N)%N][p-1];
                int not_include_ith_num = cache[(i-1)%2][j][p];

                cache[i%2][j][p] = (include_ith_num + not_include_ith_num) % DIVIDER;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T-->0) {
        cin >> N >> K;
        preprocessing();
        cout << cache[(N-1)%2][0][K] << endl;
    }
    return 0;
}
