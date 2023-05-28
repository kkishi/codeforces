#include <bits/stdc++.h>

#include "codeforces_multi.h"

int32_t cnt[640][200001];

void Main() {
  ints(n);
  int N = n * 2;
  int M = sqrt(N);
  V<int> a(n), b(n);
  cin >> a >> b;
  rep(i, n) if (a[i] <= M)++ cnt[a[i]][b[i]];

  auto count = [&](int i) {
    int ret = 0;
    rep(j, 1, M + 1) {
      int A = a[i] * j;
      int B = A - b[i];
      if (0 <= B && B <= n) ret += cnt[j][B];
    }
    return ret;
  };

  int sum = 0;
  rep(i, n) if (a[i] <= M) sum += count(i);

  int self = 0;
  rep(i, n) if (a[i] <= M && a[i] * a[i] == b[i] + b[i])++ self;

  int small = (sum - self) / 2;

  int big = 0;
  rep(i, n) if (a[i] > M) big += count(i);

  wt(small + big);

  rep(i, n) if (a[i] <= M)-- cnt[a[i]][b[i]];
}
