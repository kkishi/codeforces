#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "primes.h"

V<bool> sieve = Sieve(1001);

void Main() {
  ints(n, m);
  vector ans(n, vector(m, int(0)));
  if (!sieve[n]) {
    rep(i, m) rep(j, n) ans[j][i] = i * n + j + 1;
  } else {
    rep(i, m) rep(j, n) ans[(j + (n - 1) * i) % n][i] = i * n + j + 1;
  }
  each(e, ans) wt(e);
#ifdef DEBUG
  rep(i, n - 1) rep(j, m - 1) {
    assert(!sieve[abs(ans[i][j] - ans[i + 1][j])]);
    assert(!sieve[abs(ans[i][j] - ans[i][j + 1])]);
  }
#endif
}
