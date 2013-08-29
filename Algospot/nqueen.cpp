#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_QUEEN_COUNT 12

int N;
int answer;
int queen_position[MAX_QUEEN_COUNT];

void init();
void solve(int);
bool available(int, int);
void put(int, int);

int main() {
    int C;
    cin >> C;
    while (C-->0) {
        cin >> N;
        init();
        solve(0);
        cout << answer << endl;
    }
    return 0;
}

void init() {
    answer = 0;
}

void solve(int queen) {
    if (queen == N) {
        answer++;
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (available(queen, i)) {
            put(queen, i);
            solve(queen + 1);
        }
    }
}

bool available(int queen, int col) {
    for (int i = 0; i < queen; i++) {
        if (queen_position[i] == col)
            return false;

        if (queen - i == abs(col - queen_position[i]))
            return false;
    }

    return true;
}

void put(int queen, int col) {
    queen_position[queen] = col;
}




