#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int minimumSupervisors(vector<int> students, int K) {
    int jedai = 0;
    int remain = 0;

    for (int i = 0; i < students.size(); ++i) {
        if (students[i] == 0)
            continue;

        int need = (students[i] + K - 1) / K;
        int more = need * K - students[i];
        jedai += need;

        if (i+1 < students.size()) {
            int borrow = min(more, students[i+1]);
            students[i+1] -= borrow;
            more -= borrow;
        }

        if (i+2 < students.size()) {
            students[i+2] -= min(more, students[i+2]);
        }
    }

    return jedai;
}

vector<int> get_vector(int* arr, int s) {
    vector<int> result(s);
    for (int i = 0; i < s; ++i)
        result[i] = arr[i];
    return result;
}

int main() {
    int test1[] = {3, 6, 3};
    assert(minimumSupervisors(get_vector(test1, sizeof(test1)/sizeof(int)), 4) == 3);

    int test2[] = {1,1,1,1};
    assert(minimumSupervisors(get_vector(test2, sizeof(test2)/sizeof(int)), 4) == 2);

    int test3[] = {0,0,0,0};
    assert(minimumSupervisors(get_vector(test3, sizeof(test3)/sizeof(int)), 12345) == 0);

    int test4[] = {15, 0, 13, 4, 29, 6, 2};
    assert(minimumSupervisors(get_vector(test4, sizeof(test4)/sizeof(int)), 7) == 10);

    int test5[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68};
    assert(minimumSupervisors(get_vector(test5, sizeof(test5)/sizeof(int)), 114) == 102138);

    cout << "correct" << endl;
    return 0;
}
