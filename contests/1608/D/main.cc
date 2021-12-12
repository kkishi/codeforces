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
    mint ans = mint::Comb(2 * n - b - w, n - b);
    map<string, int> m;
    each(e, s)++ m[e];
    // If there is at least one BB or WW, the coloring becomes always valid
    // as long as it has n B cells and n W cells. Otherwise, proceed to count
    // the invalid colorings.
    if (m["BB"] == 0 && m["WW"] == 0) {
      // An invalid coloring has at least one BW and WB each, and no BB nor
      // WW.
      //
      // Here, we assume that all dominoes become either BW or WB. So,
      // except for "??", we know how each domino is colored.
      int bw = 0, wb = 0;
      each(e, s) {
        if (e == "BW" || e == "B?" || e == "?W") ++bw;
        if (e == "WB" || e == "W?" || e == "?B") ++wb;
      }
      // Assign "??" to either BW or WB such that there is atleast one BW and
      // WB each.
      int r = m["??"];
      assert(bw + wb + r == n);
      for (int BW = max(1, bw); BW <= n - max(1, wb); ++BW) {
        ans -= mint::Comb(r, BW - bw);
      }
    }
    return ans;
  }());
}
