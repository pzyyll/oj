//
// Created by czllo on 2017/9/29.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define MAXN 500000

bool prime_table[MAXN + 10];
inline void InitPrimeTable() {
    memset(prime_table, 1, sizeof(prime_table));
    prime_table[0] = prime_table[1] = 0;
    for (int i = 2; i * i <= MAXN; ++i) {
        if (prime_table[i]) {
            for (int j = i + i; j <= MAXN; j += i)
                prime_table[j] = false;
        }
    }
}

//todo 

using namespace std;

int main() {

    return 0;
}