#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, M;
    int best_x = -1;
    int best_y = -1;
    int max_hancur = -1;
    
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));
    
    for (int y = N - 1;y >= 0;y--) {
        for (int x = 0;x < M;x++) {
            cin >> matrix[y][x];
        }
    }
    
    vector<int> sum_y(N, 0);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            sum_y[y] += matrix[y][x];
        }
    }
    
    vector<int> sum_x(M, 0);
    for (int x = 0; x < M; x++) {
        for (int y = 0; y < N; y++) {
            sum_x[x] += matrix[y][x];
        }
    }
    
    for (int x = 0; x < M; x++) {
        for (int y = 0; y < N; y++) {
            int curr_sum = sum_x[x] + sum_y[y] - matrix[y][x];
            
            if (curr_sum > max_hancur) {
                max_hancur = curr_sum;
                best_x = x;
                best_y = y;
            }
        }
    }
    
    cout << best_x << " " << best_y << " " << max_hancur;
    return 0;
}