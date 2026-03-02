#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, X;
vector<int> P, V;
vector<long> C;

long min_cost = 999999;

void cariKombinasi(int i, int total_P, int total_V, long total_C) {
    if (total_C >= min_cost) {
        return;
    }
    
    if (total_P >= M && total_V >= X) {
        min_cost = total_C;
        return;
    }
    
    if (i == N) {
        return;
    }
    
    cariKombinasi(i + 1, total_P + P[i], total_V + V[i], total_C + C[i]);
    cariKombinasi(i + 1, total_P, total_V, total_C);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    cin >> N >> M >> X;
    
    P.resize(N);
    V.resize(N);
    C.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> V[i] >> C[i];
    }
    
    cariKombinasi(0, 0, 0, 0);
    
    if (min_cost == 999999) {
        cout << "-1";
    } else {
        cout << min_cost;
    }
    
    return 0;
}
