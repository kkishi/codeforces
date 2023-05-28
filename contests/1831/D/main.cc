#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  int N = n * 2;
  int M = sqrt(N);
  V<int> a(n), b(n);
  cin >> a >> b;
  map<int, map<int, int>> mp;
  rep(i, n) mp[a[i]][b[i]]++;
  VV<pair<int, int>> v(n + 1);
  each(a, mp, mp) each(b, cnt, mp) v[a].eb(b, cnt);

  auto count = [&](int ai, int aj) -> int {
    int A = ai * aj;
    if (sz(v[ai]) > sz(v[aj])) swap(ai, aj);
    const auto& bi = v[ai];
    const auto& bj = v[aj];
    int ret = 0;
    each(bi, cnti, bi) {
      auto it = lower_bound(all(bj), pair<int, int>{A - bi, 0});
      if (it != bj.end() && it->first == A - bi) ret += cnti * it->second;
    }
    return ret;
  };

  int sum = 0;
  rep(i, 1, M + 1) rep(j, 1, M + 1) sum += count(i, j);

  int self = 0;
  rep(i, n) if (a[i] <= M && a[i] * a[i] == b[i] + b[i])++ self;

  int small = (sum - self) / 2;

  int big = 0;
  rep(i, M + 1, n + 1) for (int j = 1; i * j <= N; ++j) big += count(i, j);

  wt(small + big);
}
