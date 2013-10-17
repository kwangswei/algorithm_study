#include <iostream>
#include <vector>

using namespace std;

struct Position {
    int x;
    int y;
};

vector<bool> cache;

int get_distance(Position a, Position b) {
    return (a.x - b.x)*(a.x-b.x) + (a.y - b.y) * (a.y-b.y);
}

bool solve(vector<Position>& bridges, vector<bool>& used, int cur, int& max_jump) {
    if (cur == 0)
        return true;

    if (cache[cur] == false)
        return cache[cur];

    cache[cur] = false;

    for (int i = 0; i < bridges.size() - 1; ++i) {
        if (used[i])
            continue;
        if (get_distance(bridges[cur], bridges[i]) > max_jump*max_jump)
            continue;
        used[i] = true;
        if (solve(bridges, used, i, max_jump))
            return true;
        used[i] = false;
    }

    return false;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        int J;
        cin >> J;

        Position start;
        cin >> start.x >> start.y;

        Position target;
        cin >> target.x >> target.y;

        int N;
        cin >> N;
        vector<Position> bridges(N+2);
        vector<bool> used(N+2, false);

        bridges[0] = target;
        for (int i = 0; i < N; ++i) 
            cin >> bridges[i+1].x >> bridges[i+1].y;
        bridges[N+1] = start;

        used[N+1] = true;

        cache = vector<bool>(N+2, true);

        cout << (solve(bridges, used, N+1, J) ? "YES" : "NO") << endl;
    }

    return 0;
}
