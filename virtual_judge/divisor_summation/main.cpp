//
// Created by czllo on 2017/9/29.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define MAXN 500000

using namespace std;

long long dp[MAXN + 10];

int main() {

    for (int i = 1; i <= MAXN; ++i) {
        for (int j = 2 * i; j <= MAXN; j += i) {
            dp[j] += i;
        }
    }

    int n, m;
    while (cin >> n) {
        while (n--) {
            cin >> m;
            cout << dp[m] << endl;
        }
    }

    return 0;
}
