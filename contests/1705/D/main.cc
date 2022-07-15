#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(s, t);
  if (s[0] != t[0] || s.back() != t.back()) {
    wt(-1);
    return;
  }
  V<int> S, T;
  rep(i, n - 1) {
    if (s[i] != s[i + 1]) S.eb(i);
    if (t[i] != t[i + 1]) T.eb(i);
  }
  if (sz(S) != sz(T)) {
    wt(-1);
    return;
  }
  int ans = 0;
  rep(i, sz(S)) ans += abs(S[i] - T[i]);
  wt(ans);
}
