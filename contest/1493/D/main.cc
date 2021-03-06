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
  dbg(primes.back(), M);

  V<int> idx(N + 1, -1);
  rep(i, M) idx[primes[i]] = i;

  ints(n, q);

  V<map<int, int>> cnt(M);
  rep(i, M) cnt[i][0] = n;

  V<map<int, int>> a(n);

  auto f = [&](int x) { return cnt[x].begin()->first; };

  mint g = 1;
  rep(i, M) g *= mint(primes[i]).Pow(f(i));

  dbg(g);

  V<pair<int, int>> qs;
  rep(i, n) {
    ints(ai);
    qs.eb(i + 1, ai);
  }
  rep(q) {
    ints(i, x);
    qs.eb(i, x);
  }
  int processed = 0;
  for (auto [i, x] : qs) {
    map<int, int>& A = a[i - 1];
    for (auto [k, v] : fs[x]) {
      int j = idx[k];
      int pre = f(j);
      --cnt[j][A[k]];
      if (cnt[j][A[k]] == 0) {
        cnt[j].erase(A[k]);
      }
      A[k] += v;
      ++cnt[j][A[k]];
      int pos = f(j);
      if (pos > pre) {
        g *= mint(k).Pow(pos - pre);
      }
    }
    ++processed;
    if (processed <= n) continue;
    wt(g);
  }
}
