/*
 * main.cpp
 *
 *  Created on: 2014. 2. 3.
 *      Author: kwangswei
 */
#include <cassert>

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class AlienAndSetDiv2 {
 public:
    const int dividor = 1000000007;
    const int group_a = 0;
    const int group_b = 1;

    int N;
    int K;
    map<vector<vector<int>>, int> cache;

    int getNumber(int n, int k) {
        this->N = n;
        this->K = k;
        this->cache = map<vector<vector<int>>, int>();
        auto sets = vector<vector<int>>(2, vector<int>(n,0));
        return run(sets, 2*n);
    }

    int run(vector<vector<int>> sets, int orderNum) {
        if (orderNum == 0)
            return 1;

        auto a_pos = count(sets[0].begin(), sets[0].end(), 0) - 1;
        auto b_pos = count(sets[1].begin(), sets[1].end(), 0) - 1;

        auto del_pos = max(a_pos, b_pos) + 1;
        sets[0].erase(sets[0].begin() + del_pos, sets[0].end());
        sets[1].erase(sets[1].begin() + del_pos, sets[1].end());

        if (cache.find(sets) != cache.end())
            return cache[sets];

        auto& result = cache[sets];

        if (a_pos == b_pos) {
            sets[0][a_pos] = orderNum;
            result = (result + (2 * run(sets, orderNum - 1)) % dividor) % dividor;
        }
        else {
            auto baseNum = sets[group_a][b_pos];

            for (auto diff = 1; diff <= K; ++diff) {
                auto bufSet = sets;
                auto candidateNum = baseNum - diff;
                if (candidateNum <= orderNum && putNumToBAndFillA(bufSet, b_pos, candidateNum, orderNum))
                    result = (result + run(bufSet, candidateNum - 1)) % dividor;
            }
        }

        return result;
    }

    bool putNumToBAndFillA(vector<vector<int>>& sets, int putPosOfB, int putNum, int orderNum) {
        auto space = count(sets[group_a].begin(), sets[group_a].end(), 0);
        auto required = orderNum - putNum;

        if (space < required)
            return false;

        sets[group_b][putPosOfB] = putNum;

        for (auto num = orderNum; num > putNum; --num)
            sets[group_a][--space] = num;

        return true;
    }
};

int main() {
    AlienAndSetDiv2 test;
    assert(test.getNumber(10, 3) == 59158);
    assert(test.getNumber(50, 9) == 229887715);

    return 0;
}
