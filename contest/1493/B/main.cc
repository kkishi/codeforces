#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(h, m);
  strings(s);
  each(e, s) e -= '0';
  int H = s[0] * 10 + s[1];
  int M = s[3] * 10 + s[4];
  dbg(H, M);
  while (true) {
    int h0 = H / 10;
    int h1 = H % 10;
    int m0 = M / 10;
    int m1 = M % 10;

    auto f = [](int x) {
      map<int, int> m{
          {0, 0}, {1, 1},  {2, 5},  {3, -1}, {4, -1},
          {5, 2}, {6, -1}, {7, -1}, {8, 8},  {9, -1},
      };
      return m[x];
    };
    int H0 = f(m1);
    int H1 = f(m0);
    int M0 = f(h1);
    int M1 = f(h0);
    if (H0 != -1 && H1 != -1 && M0 != -1 && M1 != -1) {
      int H = H0 * 10 + H1;
      int M = M0 * 10 + M1;
      if (H < h && M < m) {
        cout << h0 << h1 << ":" << m0 << m1 << endl;
        return;
      }
    }
    ++M;
    if (M == m) {
      M = 0;
      ++H;
      if (H == h) {
        H = 0;
      }
    }
  }
}

void Main() {
  ints(t);
  rep(t) Solve();
}
