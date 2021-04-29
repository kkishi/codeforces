#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> u(n), s(n);
  cin >> u >> s;
  VV<int> U(n);
  rep(i, n) U[u[i] - 1].pb(s[i]);
  V<int> ans(n);
  rep(i, n) {
    sort(all(U[i]), greater{});
    int N = sz(U[i]);
    V<int> s(N + 1);
    rep(j, N) s[j + 1] = s[j] + U[i][N - 1 - j];
    rep(j, N) ans[j] += s[N] - s[N % (j + 1)];
  }
  wt(ans);
}
