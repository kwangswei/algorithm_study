#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

const int MAX_INT = numeric_limits<int>::max(); 
int cache[10001];

vector<int> nums;

vector<int> from_integer(string num) {
    vector<int> result;

    for (int i = 0; i < num.size(); ++i) 
        result.push_back(num[i] - '0');

    return result;
}

bool is_all_same(int start, int end) {
    for (int i = start + 1; i < end; ++i)
        if (nums[start] != nums[i])
            return false;
    return true;
}

bool is_monotonicaly_change_by_one(int start, int end) {
    int diff = nums[start] - nums[start+1];
    for (int i = start + 1; i < end - 1; i++)
        if (nums[i] - nums[i+1] != diff)
            return false;
    return diff == 1 || diff == -1;
}

bool is_arithmetical_progression(int start, int end) {
    int diff = nums[start] - nums[start+1];
    for (int i = start + 1; i < end - 1; i++)
        if (nums[i] - nums[i+1] != diff)
            return false;
    return true;
}

bool is_in_ratation(int start, int end) {
    for (int i = start; i < end - 2; i++)
        if (nums[i] != nums[i+2])
            return false;
    return true;
}


int get_min_cost(int start, int end) {
    if (end - start < 3)
        return 10;

    if (is_all_same(start, end))
        return 1;
    if (is_monotonicaly_change_by_one(start, end))
        return 2;
    if (is_in_ratation(start, end))
        return 4;
    if (is_arithmetical_progression(start, end))
        return 5;

    return 10;
}


int solve(int idx) {
    int& min_cost = cache[idx];
    if (min_cost != -1)
        return min_cost;

    min_cost = MAX_INT;

    if (nums.size() - idx <= 5)
        return (min_cost = get_min_cost(idx, nums.size()));

    min_cost = min(min_cost, get_min_cost(idx, idx+3) + solve(idx+3));
    min_cost = min(min_cost, get_min_cost(idx, idx+4) + solve(idx+4));
    min_cost = min(min_cost, get_min_cost(idx, idx+5) + solve(idx+5));

    return min_cost;
}

int main() {
    int C;
    cin >> C;

    while (C --> 0) {
        string num;
        cin >> num;

        memset(cache, -1, sizeof(cache));

        nums = from_integer(num);
        cout << solve(0) << endl;
    }

    return 0;
}
