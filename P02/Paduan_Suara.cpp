#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int M;
    cin >> M;
    
    vector<int>tinggi_suara(M);
    
    for (int i = 0; i < M; i++) {
        cin >> tinggi_suara[i];
    }
    
    int N;
    cin >> N;
    
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < M - i - 1; j++) {
            if (tinggi_suara[j] > tinggi_suara[j + 1]) {
                int temp = tinggi_suara[j];
                tinggi_suara[j] = tinggi_suara[j + 1];
                tinggi_suara[j + 1] = temp;
            }
        }
    }
    
    int K = M / N;
    
    for (int i = 1; i < N; i++) {
        cout << tinggi_suara[i * K];
        
        if (i < N - 1) {
            cout << " ";
        }
    }
    
    return 0;
}