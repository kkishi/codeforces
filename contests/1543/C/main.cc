#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  rd(double, c, m, p, v);
  vector dp(1000, vector(1000, double(-1)));
  auto rec = [&](auto rec, int ci, int mi) -> double {
    double &d = dp[ci][mi];
    if (d < 0) {
      double C = c - ci * v + mi * v / 2;
      double M = m - mi * v + ci * v / 2;
      dbg(ci, mi, C, M);
      auto z = [](double x) -> bool { return x < 1e-9; };
      // auto z = [](double x) -> bool { return x < 0; };
      dbg(z(C), z(M));
      assert(!z(C) || !z(M));
      if (z(C) || z(M)) {
        if (z(M)) swap(C, M);
        C += v;
        M -= v / 2;
        double x = M + C / 2;
        d = 1;
        double p = 1;
        rep(i, 100) {
          if (x - i * v < 0) break;
          p *= x - i * v;
          d += p;
        }
        // d = 1 + x * 2;
        // d = 1 + x;
      } else {
        d = 1 + C * rec(rec, ci + 1, mi) + M * rec(rec, ci, mi + 1);
      }
    }
    return d;
  };
  wt(rec(rec, 0, 0));
}
