#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

double x[100];
double y[100];
double dist[100][100];
int N;
bool selected[100];

void init() {
    for (int i = 0; i < 100; ++i) {
        x[i] = y[i] = 0.0;
        selected[i] = false;
        for (int j = 0; j < 100; ++j) {
            dist[i][j] = -1.0;
        }
    }
}

void update_dist() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                dist[i][j] = 0.0;
            }
            else {
                dist[i][j] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            }
        }
    }
}

double prim() {
    int nSelected = 0;
    double solution = .0;

    selected[nSelected] = true;
    nSelected++;

    while (nSelected < N) {
        int next_node = -1;
        double next_dist = 10000000000.0;
        for (int i = 0; i < N; ++i) {
            if (!selected[i])
                continue;

            for (int j = 0; j < N; ++j) {
                if (selected[j])
                    continue;

                if (dist[i][j] < next_dist) {
                    next_dist = dist[i][j];
                    next_node = j;
                }
            }
        }

        if (next_dist > solution)
            solution = next_dist;
        selected[next_node] = true;
        nSelected++;
    }

    return solution;
}


int main() {
    int C;
    cin >> C;

    while (C-->0) {
        cin >> N;

        init();

        for (int i = 0; i < N; ++i) {
            cin >> x[i] >> y[i];
        }

        update_dist();

        printf("%.2lf\n", floor((sqrt(prim()) * 100)+0.5) / 100.0 );
    }
    return 0;
}
