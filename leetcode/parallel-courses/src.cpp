// tag: topological sort

#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
    public:
        int minimumSemesters(int N, vector<vector<int>> relations) {
            build_graph(N, relations);
            if (dfs(0) ==  false)
                return -1;
            return *max_element(depth.begin(), depth.end()) - 1;
        }

        void build_graph(int n, vector<vector<int>>& relations) {
            visited = vector<int>(n+1, NOT_VISITED);
            adj = vector<vector<int>>(n+1);
            depth = vector<int>(n+1, 1);

            for (auto r: relations)
                adj[r[0]].push_back(r[1]);

            for (auto i = 1; i <= n; i++)
                adj[0].push_back(i);
        }

        bool dfs(int n) {
            if (visited[n] == VISITING)
                return false;
            if (visited[n] == VISITED)
                return true;

            visited[n] = VISITING;

            for (auto neighbor: adj[n]) {
                if (dfs(neighbor) == false)
                    return false;
                depth[n] = max(depth[n], 1 + depth[neighbor]);
            }

            visited[n] = VISITED;
            return true;
        }

    private:
        const int NOT_VISITED = -1;
        const int VISITING = 0;
        const int VISITED = 1;

        vector<vector<int>> adj;
        vector<int> visited;
        vector<int> depth;
};

int main() {
    Solution s;

    assert(s.minimumSemesters(3, vector<vector<int>>{{1, 3}, {2, 3}}) == 2);
    assert(s.minimumSemesters(3, vector<vector<int>>{{1, 2}, {2, 3}, {3, 1}}) == -1);

    return 0;
}

