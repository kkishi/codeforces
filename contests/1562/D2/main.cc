#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, q);
  strings(s);

  V<int> sum(n + 1);
  rep(i, n) {
    int x = s[i] == '+' ? 1 : -1;
    if (!even(i)) x = -x;
    sum[i + 1] = sum[i] + x;
  }

  map<int, int> idx;
  idx[0] = n;
  int cur = 0;
  V<int> inc(n + 1, -1), dec(n + 1, -1);
  rrep(i, n) {
    int x = s[i] == '+' ? 1 : -1;
    if (!even(i)) x = -x;
    cur += x;
    idx[cur] = i;
    if (idx.count(cur + 1)) {
      inc[i] = idx[cur + 1];
    }
    if (idx.count(cur - 1)) {
      dec[i] = idx[cur - 1];
    }
  }
  auto dbl = [&](const V<int>& v) {
    vector dv(21, vector(n + 1, int(-1)));
    dv[0] = v;
    rep(i, 20) {
      rep(j, n + 1) {
        int k = dv[i][j];
        if (k != -1) k = dv[i][k];
        dv[i + 1][j] = k;
      }
    }
    return dv;
  };
  vector dinc = dbl(inc);
  vector ddec = dbl(dec);

  rep(q) {
    ints(l, r);
    --l;
    int x = sum[r] - sum[l];
    auto fnd = [&](const auto& dv, int x) {
      int i = l;
      rep(j, 21) if (hasbit(x, j)) i = dv[j][i];
      return i;
    };
    if (x == 0) {
      wt(0);
    } else if (even(x)) {
      wt(2);
      int L, R;
      if (x < 0) {
        x = -x;
        L = fnd(dinc, x / 2);
        R = fnd(dinc, x);
      } else {
        L = fnd(ddec, x / 2);
        R = fnd(ddec, x);
      }
      wt(L, R);
    } else {
      wt(1);
      int I;
      if (x < 0) {
        x = -x;
        I = fnd(dinc, x / 2 + 1);
      } else {
        I = fnd(ddec, x / 2 + 1);
      }
      wt(I);
    }
  }
}
