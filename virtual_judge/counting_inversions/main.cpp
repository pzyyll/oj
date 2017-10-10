#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 250000
#define MAXVAL 50000
#define MAXTREE 500

int N, a[MAXN + 1];
int bit[MAXVAL + 1];
int bit2[MAXTREE + 1][MAXVAL + 1];

