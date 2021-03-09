#include <bits/stdc++.h>

#include "codeforces.h"
#include "factors.h"
#include "modint.h"
#include "primes.h"

using mint = ModInt<>;

void Main() {
  const int N = 2 * 100000;
  V<map<int, int>> fs(N + 1);
  rep(i, 1, N + 1) fs[i] = Factors(i);

  V<int> primes = Primes(N);
  int M = sz(primes);

  V<int> idx(N + 1, -1);
  rep(i, M) idx[primes[i]] = i;

  ints(n, q);

  V<map<int, int>> cnt(M);
  rep(i, M) cnt[i][0] = n;

  V<pair<int, int>> qs;
  rep(i, n) {
    ints(ai);
    qs.eb(i + 1, ai);
  }
  rep(q) {
    ints(i, x);
    qs.eb(i, x);
  }

  V<map<int, int>> a(n);
  auto f = [&](int x) { return cnt[x].begin()->first; };
  mint g = 1;

  rep(qi, sz(qs)) {
    auto [i, x] = qs[qi];
    map<int, int>& A = a[i - 1];
    for (auto [k, v] : fs[x]) {
      int j = idx[k];
      int pre = f(j);
      if (--cnt[j][A[k]] == 0) {
        cnt[j].erase(A[k]);
      }
      A[k] += v;
      ++cnt[j][A[k]];
      int pos = f(j);
      g *= mint(k).Pow(pos - pre);
    }
    if (qi >= n) wt(g);
  }
}
