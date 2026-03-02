#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int hitungXY(string Kromosom, int i) {
    if (i >= Kromosom.length() - 1) {
        return 0;
    }
        
    if (Kromosom[i] == 'X' && Kromosom[i + 1] == 'Y') {
        return 1 + hitungXY(Kromosom, i + 1);
    } else {
        return 0 + hitungXY(Kromosom, i + 1);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string Kromosom;
    cin >> Kromosom;
    
    int totalXY = hitungXY(Kromosom, 0);
    
    if (totalXY % 2 == 0 && totalXY > 0) {
        cout << "True";
    } else {
        cout << "False";
    }
    
    return 0;
}
