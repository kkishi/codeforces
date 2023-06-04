#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  V<int> q(n + 1);
  rep(i, n) q[p[i]] = i + 1;
  pair<int, int> ans;
  int mi = big;
  auto f = [&](int i, int j) {
    swap(p[i], p[j]);
    q[p[i]] = i + 1;
    q[p[j]] = j + 1;
    set<int> st;
    int mav = -big, miv = big;
    int cnt = 0;
    rep(i, 1, n + 1) {
      int v = q[i];
      st.insert(v);
      chmax(mav, v);
      chmin(miv, v);
      if (mav - miv + 1 == sz(st)) ++cnt;
    }
    if (chmin(mi, cnt)) ans = {i + 1, j + 1};
    swap(p[i], p[j]);
    q[p[i]] = i + 1;
    q[p[j]] = j + 1;
  };
  f(0, q[1] - 1);
  f(n - 1, q[1] - 1);
  f(0, q[2] - 1);
  f(n - 1, q[2] - 1);
  wt(ans.first, ans.second);
  assert(mi == 2);
}
