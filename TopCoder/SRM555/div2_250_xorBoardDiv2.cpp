#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class XorBoardDivTwoOptimized {
    public:
        int theMax(vector<string> board);
    private:
};

int XorBoardDivTwoOptimized::theMax(vector<string> board) {
    vector<int> countOfRows = vector<int>(board.size(), 0);
    vector<int> countOfCols = vector<int>(board[0].size(), 0);

    int totalOnes = 0;
    int crossCount = board[0].size() + board.size() - 1;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            countOfRows[i] += board[i][j] == '0';
            countOfCols[j] += board[i][j] == '0';
            totalOnes += board[i][j] - '0';
        }
    }

    int maxChange = -100;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            int countOfZeros = countOfRows[i] + countOfCols[j] - (board[i][j] == '0');
            int countOfOnes = crossCount - countOfZeros;
            maxChange = max(maxChange , countOfZeros - countOfOnes + (board[i][j] == '1' ? 1 : -1));
        }
    }
    return totalOnes + maxChange;
}

class XorBoardDivTwo {
    public:
        int theMax(vector<string> board);
    private:
        void flip_row(vector<string>& board, int row);
        void flip_col(vector<string>& board, int col);
        int getCountOfOnes(vector<string>& board);
};

int XorBoardDivTwo::theMax(vector<string> board) {
    int answer = 0;

    for (int i = 0; i < board.size(); ++i) {
        flip_row(board, i);
        for (int j = 0; j < board[i].size(); ++j) {
            flip_col(board, j);
            answer = max(answer, getCountOfOnes(board));
            flip_col(board, j);
        }
        flip_row(board, i);
    }

    return answer;
}

void XorBoardDivTwo::flip_row(vector<string>& board, int row) {
    for (int i = 0; i < board[row].size(); ++i)
        board[row][i] = board[row][i] == '0' ? '1' : '0';
}

void XorBoardDivTwo::flip_col(vector<string>& board, int col) {
    for (int i = 0; i < board.size(); ++i)
        board[i][col] = board[i][col] == '0' ? '1' : '0';
}

int XorBoardDivTwo::getCountOfOnes(vector<string>& board) {
    int cnt = 0;
    for (const auto s : board)
        cnt += count(s.begin(), s.end(), '1');

    return cnt;
}

int main() {
    XorBoardDivTwo test;
    XorBoardDivTwoOptimized test2;

    cout << test.theMax({"101", "010", "101"}) << endl;
    cout << test.theMax({"000000000000000000000000",
            "011111100111111001111110",
            "010000000100000001000000",
            "010000000100000001000000",
            "010000000100000001000000",
            "011111100111111001111110",
            "000000100000001000000010",
            "000000100000001000000010",
            "000000100000001000000010",
            "011111100111111001111110",
            "000000000000000000000000"}) << endl;


    cout << test2.theMax({"101", "010", "101"}) << endl;
    cout << test2.theMax({"000000000000000000000000",
            "011111100111111001111110",
            "010000000100000001000000",
            "010000000100000001000000",
            "010000000100000001000000",
            "011111100111111001111110",
            "000000100000001000000010",
            "000000100000001000000010",
            "000000100000001000000010",
            "011111100111111001111110",
            "000000000000000000000000"}) << endl;

    return 0;
}
