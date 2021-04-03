#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  V<int> cnt(m);
  each(e, a)++ cnt[e % m];
  int ans = 0;
  rep(i, m) if (cnt[i]) {
    ++ans;
    int j = (m - i) % m;
    if (j == i) {
      cnt[i] = 0;
    } else {
      int I = i, J = j;
      if (cnt[I] > cnt[J]) swap(I, J);
      cnt[J] -= min(cnt[J], cnt[I] + 1);
      cnt[I] = 0;
    }
  }
  rep(i, m) ans += cnt[i];
  wt(ans);
}
