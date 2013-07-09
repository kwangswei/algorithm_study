#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

enum {COL, ROW};

int yard[101][101];
int maxRowCol[2][101];

int N, M;

bool checkRow(int col, int val)
{
    for (int i = 0; i < M; i++)
        if ( yard[col][i] > val)
            return false;
    return true;
}

bool checkCol(int row, int val)
{
    for (int i = 0; i < N; i++)
        if (yard[i][row] > val)
            return false;
    return true;
}

bool getAnswer()
{
    // get max
    memset(maxRowCol, -1, sizeof(maxRowCol));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            maxRowCol[COL][i] = max( yard[i][j], maxRowCol[COL][i]);
            maxRowCol[ROW][j] = max( yard[i][j], maxRowCol[ROW][j]);
        }
    }

    // if less than max -> check row & col

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (yard[i][j] < maxRowCol[COL][i] && checkCol(j, yard[i][j]) == false)
                return false;
            if (yard[i][j] < maxRowCol[ROW][j] && checkRow(i, yard[i][j]) == false)
                return false;
        }
    }
    return true;
}

int main() 
{
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++)
    {
        cin >> N >> M;
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> yard[i][j];

        printf("Case #%d: %s\n", k, getAnswer() ? "YES" : "NO");        
    }

}

