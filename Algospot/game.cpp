#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> solve(vector<vector<int> > W, int N, int K) {
    vector<bool> done = vector<bool>(N, false);
    int doneCnt = 0;

    int currentTime = 0;
    int call = 0;
    int startCallTime = 0;

    while (doneCnt < K) {
        vector<int> candidate;
        for (int i = 0; i < N; ++i) {
            if (done[i])
                continue;

            if (W[i][call] + startCallTime <= currentTime) {
                candidate.push_back(i);
            }
        }

        if (candidate.size() == 1) {
            done[candidate[0]] = true;
            call++;
            doneCnt++;
            startCallTime = currentTime + 1;
        }
        else if (candidate.size() > 1)
            return candidate;

        currentTime++;
    }

    vector<int> remain;
    for (int i = 0; i < N; ++i) {
        if (done[i] == false)
            remain.push_back(i);
    }

    return remain;
}

int main() {
    int T;
    int N, K;

    cin >> T;
    while (T-->0) {
        cin >> N >> K;

        vector<vector<int> > W = vector<vector<int> >(N, vector<int>(K, 0));
        for (int i = 0; i < N; ++i) 
            for (int j = 0; j < K; ++j)
                cin >> W[i][j];

        vector<int> result = solve(W, N, K);

        for (const auto n : result)
            cout << n+1 << " ";
        cout << endl;
    }

    return 0;
}
    
