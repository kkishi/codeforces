#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  int ans = big;
  V<int> mns(2, big);
  V<int> sum(2);
  V<int> cnt(2);
  rep(i, n) {
    int I = i % 2;
    ++cnt[I];
    sum[I] += c[i];
    chmin(mns[I], c[i]);
    if (i < 1) continue;
    int cost = 0;
    rep(i, 2) cost += sum[i] + (n - cnt[i]) * mns[i];
    chmin(ans, cost);
  }
  wt(ans);
}
