/*
 * @Create by Caizhili on 20170914
 * Primitive roots
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 1000000

/*
 * @Brief 素数筛选法
 */
bool prime_table[MAXN + 10];
inline void InitPrimeTable() {
    memset(prime_table, 1, sizeof(prime_table));
    prime_table[0] = prime_table[1] = 0;
    prime_table[2] = 1;
    for (int i = 2; i * i <= MAXN; ++i) {
        if (prime_table[i]) {
            for (int j = i + i; j <= MAXN; j += i) {
                prime_table[j] = false;
            }
        }
    }
}

inline bool IsPrime(int num) {
    return prime_table[num];
}

/*
 * @Brief binary gcd
 * https://en.wikipedia.org/wiki/Binary_GCD_algorithm
 */
unsigned int Gcd(unsigned int u, unsigned int v) {
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    if (~u & 0x1) {
        if (v & 0x1)
            return Gcd(u >> 1, v);
        else
            return Gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 0x1)
        return Gcd(u, v >> 1);

    if (u > v)
        return Gcd((u - v) >> 1, v);

    return Gcd((v - u) >> 1, u);
}

/*
 * @Brief 欧拉函数
 * http://www.geeksforgeeks.org/eulers-totient-function/
 */
int Phi(int n) {
    if (IsPrime(n))
        return n - 1;

    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}

void GetPrimeFactor(int n, vector<int> &pf) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (IsPrime(i) && res % i == 0) {
            while (res % i == 0)
                res /= i;
            pf.push_back(i);
        }
    }
}

long long MontModMult(long long a, long long b, long long m) {
    long long ans = 1;
    long long tmp = a % m;
    while (b) {
        if (b & 0x1)
            ans = ans * tmp % m;
        tmp = tmp * tmp % m;
        b >>= 1;
    }
    return ans;
}

/*
 * @Brief Get the minimum primitive root for n;
 */
int GetMinimumPr(int n) {
    if (n <= 2)
        return n - 1;
    for (int i = 2; i < n; ++i) {
        if (Gcd(i, n) == 1) {
            bool find = true;
            int phi = Phi(n);
            vector<int> pf;
            GetPrimeFactor(phi, pf);
            for (unsigned j = 0; j < pf.size(); ++j) {
                if (MontModMult(i, phi / pf[j], n) == 1)
                    find = false;
            }
            if (find)
                return i;
        }
    }
    return 0;
}

/*
 * @Brief
 * if n have primitive root, n = 1, 2, 4, p^k, 2p^k
 * p is odd prime
 */
bool Exist(int n) {
    if (n == 2 || n == 4 || IsPrime(n))
        return true;
    if (n % 2 == 0)
        n /= 2;

    for (int i = 3; i <= n; i += 2) {
        if (IsPrime(i) && n % i == 0) {
            while (n % i == 0)
                n /= i;
            break;
        }
    }

    if (n == 1)
        return true;
    return false;
}

void Solve(int n) {
    if (!Exist(n)) {
        cout << "-1" << endl;
        return;
    }

    vector<int> res;
    int g = GetMinimumPr(n);
    int phi = Phi(n);
    for (int i = 3; i < phi; i += 2) {
        if (Gcd(i, phi) == 1) {
            int a = MontModMult(g, i, n);
            res.push_back(a);
        }
    }

    res.push_back(g);
    sort(res.begin(), res.end());

    for (unsigned i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i != res.size() - 1)
            cout << " ";
    }
    cout << endl;
}

int main() {
    InitPrimeTable();
    int a;
    while (cin >> a) {
        Solve(a);
    }

    return 0;
}
