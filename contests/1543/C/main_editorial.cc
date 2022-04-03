#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  rd(double, c, m, p, v);
  int V = round(v * 1e6);  // These round calls are necessary, otherwise WA
  wt(Fix([&](auto rec, int C, int M) -> double {
    if (C == 0 && M == 0) return 1;
    if (C == 0) return 1 + (M / 1e6) * rec(0, max(0, M - V));
    if (M == 0) return 1 + (C / 1e6) * rec(max(0, C - V), 0);
    double ret = 1;
    {
      int x = min(C, V);
      ret += (C / 1e6) * rec(C - x, M + x / 2);
    }
    {
      int x = min(M, V);
      ret += (M / 1e6) * rec(C + x / 2, M - x);
    }
    return ret;
  })(round(c * 1e6), round(m * 1e6)));
}
