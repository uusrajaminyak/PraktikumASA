#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, T;
    
    if (!(cin >> N >> T)) {
        return 0;
    }
    
    vector<int> d, f;
    
    for (int i = 0; i < N;i++) {
        int durasi, fokus;
        cin >> durasi >> fokus;
        
        if (durasi < 5) {
            d.push_back(durasi);
            f.push_back(fokus);
        }
    }
    
    int M = d.size();
    
    if (M == 0) {
        cout << 0;
        return 0;
    }
    
    vector<vector<int>> dp(T + 1, vector<int>(M, -1));
    
    for (int i = 0; i < M; i++) {
        if (d[i] <= T) {
            dp[d[i]][i] = f[i];
        }
    }
    
    int max_fokus = 0;
    
    for (int t = 0; t <= T; t++) {
        for (int i = 0; i < M; i++) {
            if (dp[t][i] != -1) {
                max_fokus = max(max_fokus, dp[t][i]);
                for (int j = 0; j < M; j++) {
                    if (i != j && t + d[j] <= T) {
                        dp[t + d[j]][j] = max(dp[t + d[j]][j], dp[t][i] + f[j]);
                    }
                }
            }
        }
    }
    
    cout << max_fokus;
    
    return 0;
}