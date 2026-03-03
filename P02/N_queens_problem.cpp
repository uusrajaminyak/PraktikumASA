#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
vector<int> board;
bool found = false;

bool safe (int curr_row, int test_col) {
    for (int i = 0; i < curr_row; i++) {
        int queen_col_before = board[i];
        
        if (queen_col_before == test_col) {
            return false;
        }
        
        if (abs(i - curr_row) == abs(queen_col_before - test_col)) {
            return false;
        }
    }
    
    return true;
}

void place_queen(int row) {
    if (found) {
        return;
    }
    
    if (row == N) {
        found = true;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j) {
                    cout << "Q";
                } else {
                    cout << ".";
                }
            }
            cout << "\n";
        }
        return;
    }
    
    for (int col = 0; col < N; col++) {
        if (safe(row, col)) {
            board[row] = col;
            place_queen(row + 1);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    if (cin >> N) {
        board.resize(N, -1);
        place_queen(0);
        if (!found) {
            cout << "Kerajaan tidak dapat dilindungi!";
        }
    }
    return 0;
}