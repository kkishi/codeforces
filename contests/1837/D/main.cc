#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(s);

  int curr = 0;
  V<pair<int, int>> seg;
  seg.eb(0, 0);
  rep(i, n) {
    int next = curr + (s[i] == '(' ? 1 : -1);
    if (next == 0) {
      seg.eb(i + 1, curr > 0 ? 1 : 2);
    }
    curr = next;
  }
  if (curr != 0) {
    wt(-1);
  } else {
    set<int> st;
    rep(i, 1, sz(seg)) st.insert(seg[i].second);
    if (sz(st) == 1) rep(i, 1, sz(seg)) seg[i].second = 1;
    wt(sz(st));
    V<int> ans(n);
    rep(i, 1, sz(seg)) {
      auto [l, _] = seg[i - 1];
      auto [r, c] = seg[i];
      rep(i, l, r) ans[i] = c;
    }
    wt(ans);
  }
}
