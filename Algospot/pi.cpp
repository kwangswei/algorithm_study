#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <cstring>

using namespace std;

int get_min_cost(string num);
vector<int> get_nums_array_from(string num);
int get_min_cost(vector<int>& nums, int index);
int get_cost(vector<int>& nums, int index, int count);
bool is_all_same(vector<int>& nums, int start, int end);
bool is_monotonically_changed_by_one(vector<int>& nums, int start, int end);
bool is_rotated(vector<int>& nums, int start, int end);
bool is_arithmetic_sequence(vector<int>& nums, int start, int end);

int cache[10001];

int main() {
    int N;
    cin >> N;

    while (N --> 0) {
        string num_str;
        cin >> num_str;

        memset(cache, -1, sizeof(cache));
        cout << get_min_cost(num_str) << endl;
    }
    
    return 0;
}

int get_min_cost(string num) {
   vector<int> nums = get_nums_array_from(num);
    
   return get_min_cost(nums, 0);
}

vector<int> get_nums_array_from(string num) {
    vector<int> result = vector<int>(num.size());
    for (int i = 0; i < num.size(); ++i)
        result[i] = num[i] -'0';

    return result;
}

int get_min_cost(vector<int>& nums, int index) {
    int& cost = cache[index];

    if (cost != -1)
        return cost;

    cost = numeric_limits<int>::max();

    if (nums.size() - index <= 5)
        return (cost = get_cost(nums, index, nums.size()));

    for (int count = 3; count < 6; count++)
        cost = min(cost, get_cost(nums, index, index + count) + get_min_cost(nums, index + count));

    return cost;
}

int get_cost(vector<int>& nums, int start, int end) {
    if (end - start < 3)
        return 10;

    if (is_all_same(nums, start, end))
        return 1;

    if (is_monotonically_changed_by_one(nums, start, end))
        return 2;

    if (is_rotated(nums, start, end))
        return 4;

    if (is_arithmetic_sequence(nums, start, end))
        return 5;

    return 10;
}


bool is_all_same(vector<int>& nums, int start, int end) {
    for (int i = start + 1; i < end; ++i) {
        if (nums[start] != nums[i])
            return false;
    }
    return true;
}

bool is_monotonically_changed_by_one(vector<int>& nums, int start, int end) {
    int diff = nums[start] - nums[start+1];
    for (int i = start + 1; i < end - 1; ++i) {
        if (nums[i] - nums[i+1] != diff)
            return false;
    }
    return diff == 1 || diff == -1;
}

bool is_rotated(vector<int>& nums, int start, int end) {
    for (int i = start; i < end - 2; ++i) {
        if (nums[i] != nums[i+2])
            return false;
    }
    return true;
}

bool is_arithmetic_sequence(vector<int>& nums, int start, int end) {
    int diff = nums[start] - nums[start+1];
    for (int i = start + 1; i < end - 1; ++i) {
        if (nums[i] - nums[i+1] != diff)
            return false;
    }
    return true;
}
