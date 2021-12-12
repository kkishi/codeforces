#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  wt([]() -> mint {
    ints(n);
    V<string> s(n);
    cin >> s;
    int b = 0, w = 0;
    each(e, s) each(c, e) if (c != '?')++(c == 'B' ? b : w);
    if (b > n || w > n) return 0;
    mint ans = mint::Comb(2 * n - b - w, n - b);
    map<string, int> m;
    each(e, s)++ m[e];
    if (m["BB"] == 0 && m["WW"] == 0) {
      int bw = 0, wb = 0;
      each(e, s) {
        if (e == "BW" || e == "B?" || e == "?W") ++bw;
        if (e == "WB" || e == "W?" || e == "?B") ++wb;
      }
      int r = m["??"];
      assert(bw + wb + r == n);
      for (int BW = max(1, bw); BW <= n - max(1, wb); ++BW) {
        ans -= mint::Comb(r, BW - bw);
      }
    }
    return ans;
  }());
}
