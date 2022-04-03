#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  rd(double, c, m, p, v);
  vector dp(100, vector(100, double(-1)));
  wt(Fix([&](auto rec, int ci, int mi) -> double {
    double &d = dp[ci][mi];
    if (d < 0) {
      double C = c - ci * v + mi * v / 2;
      double M = m - mi * v + ci * v / 2;
      auto z = [](double x) -> bool { return x < 1e-9; };
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
      } else {
        d = 1 + C * rec(ci + 1, mi) + M * rec(ci, mi + 1);
      }
    }
    return d;
  })(0, 0));
}
