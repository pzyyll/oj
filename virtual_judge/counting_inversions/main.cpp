#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 250000
#define MAXVAL 50000
#define MAXTREE 500

int N, a[MAXN + 1];
int bit[MAXVAL + 1];
int bit2[MAXTREE + 1][MAXVAL + 1];

//可以优化几毫秒
inline int scan() {
  int x = 0;
  char c = getchar_unlocked();
  while (c < '0' || c > '9') {
    c = getchar_unlocked();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar_unlocked();
  }
  return x;
}

void update(int idx, int idy, int val) {
  for (int x = idx; x <= MAXTREE; x += x & -x)
    for (int y = idy; y <= MAXVAL; y += y & -y)
      bit2[x][y] += val;
}

int query(int idx, int idy) {
  int ret = 0;

  for (int x = idx; x > 0; x -= x & -x)
    for (int y = idy; y > 0; y -= y & -y)
      ret += bit2[x][y];

  return ret;
}

int countInv(int pos) {
  int x = (pos + MAXTREE - 1) / MAXTREE;
  int ret = query(x - 1, MAXVAL) - query(x - 1, a[pos]) + query(MAXTREE, a[pos] - 1) - query(x, a[pos] - 1);

  int r = min(x * MAXTREE, N), l = x * MAXTREE - (MAXTREE - 1);

  for (int i = l; i < pos; ++i)
    if (a[i] > a[pos]) ++ret;

  for (int i = pos + 1; i <= r; ++i)
    if (a[i] < a[pos]) ++ret;

  return ret;
}

int main() {
  int Q;

  N = scan();

  for (int i = 1; i <= N; ++i)
    a[i] = scan();

  long long inv = 0;

  for (int i = 1; i <= N; ++i) {
    inv += i - 1;

    for (int x = a[i]; x > 0; x -= x & -x)
      inv -= bit[x];

    for (int x = a[i]; x <= MAXN; x += x & -x)
      ++bit[x];
  }

  for (int i = 1; i <= N; ++i)
    update((i + MAXTREE - 1) / MAXTREE, a[i], 1);

  Q = scan();

  int x, y;

  while (Q--) {
    x = scan(), y = scan();

    inv -= countInv(x);

    int idx = (x + MAXTREE - 1) / MAXTREE;

    update(idx, a[x], -1);
    update(idx, y, 1);
    a[x] = y;

    inv += countInv(x);

    printf("%lld\n", inv);
  }

  return 0;
}