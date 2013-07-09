#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum {X, O};
enum {X_WON, O_WON, DRAW, NOT_COMPLETED};

int getGameResult(const vector<string>& board) {
    int sumOfRow[4][2] = {0,};
    int sumOfCol[4][2] = {0,};
    int sumOfDia[2][2] = {0,};
    bool isEmpty = false;


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 'X') {
                sumOfRow[i][X]++;
                sumOfCol[j][X]++;

                if ( i==j)
                    sumOfDia[0][X]++;
                else if (i+j==3)
                    sumOfDia[1][X]++;
            }
            else if (board[i][j] == 'O') {
                sumOfRow[i][O]++;
                sumOfCol[j][O]++;
                if ( i==j)
                    sumOfDia[0][O]++;
                else if (i+j==3)
                    sumOfDia[1][O]++;

            }
            else if (board[i][j] == 'T') {
                sumOfRow[i][X]++;
                sumOfRow[i][O]++;
                sumOfCol[j][X]++;
                sumOfCol[j][O]++;

                if ( i==j){
                    sumOfDia[0][X]++;
                    sumOfDia[0][O]++;
                }
                else if (i+j==3)
                {
                    sumOfDia[1][X]++;
                    sumOfDia[1][O]++;
                }
            }
            else
                isEmpty = true;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (sumOfRow[i][X] == 4 || sumOfCol[i][X] == 4)
            return X_WON;
        else if ( sumOfRow[i][O] == 4 || sumOfCol[i][O] == 4)
            return O_WON;
    }

    if ( sumOfDia[0][X] == 4 || sumOfDia[1][X] == 4 )
        return X_WON;
    else if ( sumOfDia[0][O] == 4 || sumOfDia[1][O] == 4)
        return O_WON;

    if ( isEmpty )
        return NOT_COMPLETED;

    return DRAW;

}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        vector<string> board(4);
        for (int j = 0; j < 4; j++ )
            cin >> board[j];

        cout << "Case #" << i << ": ";
        switch (getGameResult(board)) {
            case X_WON:
                cout << "X won" << endl;
                break;
            case O_WON:
                cout << "O won" << endl;
                break;
            case DRAW:
                cout << "Draw" << endl;
                break;
            case NOT_COMPLETED:
                cout << "Game has not completed" << endl;
                break;
        }
    }
    return 0;
}
