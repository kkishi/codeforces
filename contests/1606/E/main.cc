// NOTE: This solution TLEs.
#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

int Naive(int n, int x) {
  V<int> v(n);
  int ans = 0;
  auto rec = [&](auto rec, int depth) {
    if (depth == n) {
      multiset<int> st(all(v));
      while (sz(st) > 1) {
        multiset<int> nst;
        each(e, st) {
          int ne = e - (sz(st) - 1);
          if (ne > 0) nst.insert(ne);
        }
        swap(st, nst);
      }
      if (sz(st) == 0) ++ans;
      return;
    }
    rep(i, 1, x + 1) {
      v[depth] = i;
      rec(rec, depth + 1);
    }
  };
  rec(rec, 0);
  return ans;
}

void Main() {
  ints(n, x);
  wt(Naive(n, x));
}
