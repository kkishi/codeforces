#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n);
  VV<int> a;
  a.resize(n);
  rep(i, n) {
    ints(c);
    a[i].resize(c);
    cin >> a[i];
  }
  ints(m);
  set<V<int>> banned;
  rep(m) {
    V<int> b(n);
    cin >> b;
    each(e, b)-- e;
    banned.insert(b);
  }
  V<int> ans;
  V<int> build(n);
  rep(i, n) build[i] = sz(a[i]) - 1;
  if (find(all(banned), build) == banned.end()) {
    ans = build;
  } else {
    int maxi = 0;
    each(e, banned) {
      int sum = 0;
      rep(i, n) sum += a[i][e[i]];
      rep(i, n) {
        rep(j, 2) {
          V<int> E = e;
          int d[] = {-1, 1};
          E[i] += d[j];
          if (0 <= E[i] && E[i] < sz(a[i])) {
            if (!banned.count(E)) {
              if (chmax(maxi, sum - a[i][e[i]] + a[i][E[i]])) {
                ans = E;
              }
            }
          }
        }
      }
    }
  }
  each(e, ans)++ e;
  wt(ans);
}
