#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n, m);
  strings(s);
  string abc = "abc";
  VV<int> cost;
  do {
    V<int> v(n + 1);
    rep(i, n) v[i + 1] = v[i] + (abc[i % 3] != s[i]);
    cost.eb(v);
  } while (next_permutation(all(abc)));
  rep(m) {
    ints(l, r);
    int ans = big;
    each(e, cost) { chmin(ans, e[r] - e[l - 1]); }
    wt(ans);
  }
}
