#pragma once

#include <vector>


class UnionFind {
    public:
        UnionFind(int n) : parent(n+1) {
            std::iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }

        void merge(int x, int y) {
            auto xx = find(x);
            auto yy = find(y);
            if (xx != yy)
                parent[yy] = xx;
        }

    private:
        std::vector<int> parent;
};
