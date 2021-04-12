#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  V<int> t(q);
  cin >> t;
  V<int> top_idx(51, -1);
  rep(i, n) if (top_idx[a[i]] == -1) top_idx[a[i]] = i;
  V<bool> seen(51);
  V<int> top;
  V<int> v;
  each(ti, t) {
    int idx = -1;
    rep(i, sz(top)) {
      if (top[i] == ti) {
        idx = i;
      }
    }
    if (idx != -1) {
      v.pb(idx + 1);
      rrep(j, idx) swap(top[j], top[j + 1]);
      continue;
    }
    int ans = top_idx[ti];
    seen[ti] = true;
    rep(i, 1, 51) if (seen[i] && top_idx[i] > top_idx[ti])++ ans;
    v.pb(ans + 1);
    V<int> ntop;
    ntop.pb(ti);
    each(e, top) ntop.pb(e);
    swap(top, ntop);
    dbg(top);
  }
  wt(v);
}
