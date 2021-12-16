#include <bits/stdc++.h>

#include "codeforces_interactive.h"

void Solve() {
  ints(n);
  V<int> r1;
  auto ask = [&](int i, int j, int k) -> int {
    assert(sz(set{i, j, k}) == 3);
    wt_flush('?', i + 1, j + 1, k + 1);
    ints(r);
    dbg(i, j, k, r);
    return r;
  };
  rep(i, n / 3) {
    int a = i * 3;
    int b = a + 1;
    int c = a + 2;
    r1.pb(ask(a, b, c));
  }
  dbg(r1);
  V<int> zs, os;
  rep(i, n / 3)(r1[i] == 0 ? zs : os).eb(i);
  assert(!zs.empty() && !os.empty());
  dbg(zs, os);

  int zero = -1, one = -1;
  V<int> r2(n, -1);
  {
    int x = zs[0] * 3;
    int y = x + 1;
    bool all_zero = true;
    V<int> r(3);
    rep(j, 3) {
      int z = os[0] * 3 + j;
      r[j] = ask(x, y, z);
      if (r[j] == 1) {
        r2[z] = 1;
        one = z;
        all_zero = false;
      }
    }
    if (all_zero) {
      r2[x] = r2[y] = 0;
      zero = x;
    } else {
      rep(j, 3) {
        int z = os[0] * 3 + j;
        if (r[j] == 0) {
          r2[z] = 0;
        } else {
          r2[z] = 1;
          one = z;
        }
      }
      r2[x + 2] = 0;
      zero = x + 2;
    }
  }
  dbg(r2);
  {
    int x = os[0] * 3;
    int y = x + 1;
    bool all_one = true;
    V<int> r(3);
    rep(j, 3) {
      int z = zs[0] * 3 + j;
      r[j] = ask(x, y, z);
      if (r[j] == 0) {
        r2[z] = 0;
        zero = z;
        all_one = false;
      }
    }
    if (all_one) {
      r2[x] = r2[y] = 1;
      one = x;
    } else {
      rep(j, 3) {
        int z = zs[0] * 3 + j;
        if (r[j] == 0) {
          r2[z] = 0;
          zero = z;
        } else {
          r2[z] = 1;
        }
        r2[x + 2] = 1;
        one = x + 2;
      }
    }
  }
  assert(zero != -1 && one != -1);
  dbg(zero, one);
  dbg(r2);

  rep(i, 3) {
    if (int j = zs[0] * 3 + i; r2[j] == -1) r2[j] = ask(one, zero, j);
    if (int j = os[0] * 3 + i; r2[j] == -1) r2[j] = ask(one, zero, j);
  }

  rep(i, n / 3) {
    if (i == zs[0] || i == os[0]) continue;
    int x = i * 3;
    int y = x + 1;
    if (r1[i] == 0) {
      int z = one;
      int r = ask(x, y, z);
      dbg(x, y, z, r);
      if (r == 0) {
        r2[x] = r2[y] = 0;
        r2[x + 2] = ask(one, zero, x + 2);
      } else {
        r2[x + 2] = 0;
        int r = ask(one, zero, x);
        r2[x] = r;
        r2[y] = 1 - r;
      }
    } else {
      int z = zero;
      int r = ask(x, y, z);
      dbg(x, y, z, r);
      if (r == 1) {
        r2[x] = r2[y] = 1;
        r2[x + 2] = ask(one, zero, x + 2);
      } else {
        r2[x + 2] = 1;
        int r = ask(one, zero, x);
        r2[x] = r;
        r2[y] = 1 - r;
      }
    }
  }
  dbg(r2);

  V<int> ans;
  rep(i, n) if (r2[i] == 0) ans.eb(i + 1);
  cout << "! " << sz(ans) << " ";
  wt_flush(ans);
  dbg(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}
