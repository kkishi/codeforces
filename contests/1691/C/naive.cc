#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  strings(s);
  int ans = big;
  Fix([&](auto rec, int depth) {
    // dbg(depth, s);
    if (depth == k) {
      int sum = 0;
      rep(i, n - 1) sum += 10 * (s[i] == '1') + (s[i + 1] == '1');
      chmin(ans, sum);
      return;
    }
    rep(i, n - 1) {
      swap(s[i], s[i + 1]);
      rec(depth + 1);
      swap(s[i], s[i + 1]);
    }
  })(0);
  wt(ans);
}
