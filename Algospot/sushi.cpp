#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Sushi {
    int priority;
    int price;
};

vector<Sushi> data;

int get_max_priority(int n, int m);

int main() {
    int C;
    cin >> C;

    while (C-->0) {
        int N, M;
        cin >> N >> M;
        data = vector<Sushi>(N);

        for (int i = 0; i < N; ++i) {
            cin >> data[i].price >> data[i].priority;
            data[i].price /= 100;
        }

        M /= 100;
        cout << get_max_priority(N, M) << endl;
    }

    return 0;
}

int get_max_priority(int n, int m) {
    int priority[20001] = {0,};
    int max_priority = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= data[j].price) {
                priority[i%20001] = max(priority[i%20001], priority[(i-data[j].price)%20001] + data[j].priority);
            }
        }
        max_priority = max(max_priority, priority[i%20001]);
    }
    return max_priority;
}
