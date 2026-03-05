/* Mohon untuk Mengisi identitas berikut sebelum mengerjakan
 Nama : Yustinus Hendi S
 NIM  : 24060124130114
 Lab  : A1
*/

#include <bits/stdc++.h>
using namespace std;

long power (long base, long exp, long mod) {
    long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long nCr(long n, long r, long mod) {
    if (r < 0 || r > n) {
        return 0;
    }
    
    if (r == 0 || r == n) {
        return 1;
    }
    
    if (r > n / 2) {
        r = n - r;
    }
    
    long num = 1, den = 1;
    for (long i = 0; i < r; i++) {
        num = (num * (n - i)) % mod;
        den = (den * (i + 1)) % mod;
    }
    
    long res = (num * power(den, mod - 2, mod)) % mod;
    return res;
}

int main() {
    
    int N, K;
    int mod = 1000000007;
    
    cin >> N >> K;
    
    vector<int> A(N + 1);
    vector<int> P(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        P[i] = P[i - 1] + A[i];
    }
    
    int S = P[N];
    if (S % K != 0) {
        cout << 0;
        return 0;
    }
    
    int T = S / K;
    
    if (T == 0) {
        int C = 0;
        
        for (int i = 1; i < N; i++) {
            if (P[i] == 0) {
                C++;
            }
        }
        
        if ( C < K - 1) {
            cout << 0;
        } else {
            cout << nCr(C, K - 1, mod);
        }
    } else {
        vector<long> dp(K, 0);
        dp[0] = 1;
        
        for (int i = 1; i < N; i++) {
            if (P[i] % T == 0) {
                long j = P[i] / T;
                if (j >= 1 && j < K) {
                    dp[j] = (dp[j] + dp[j - 1]) % mod;
                }
            }
        }
        cout << dp[K - 1];
    }
    return 0;
}


/*Gimana, Aman ?
Tinggalkan saran di sini : 

*/