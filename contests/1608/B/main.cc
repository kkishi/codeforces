#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, a, b);
  if (a + b > n - 2) {
    wt(-1);
    dbg("x");
    return;
  }
  if (abs(a - b) > 1) {
    wt(-1);
    dbg("y");
    return;
  }
  rep(i, 2) {
    V<int> ans;
    int l = 1, r = n;
    int A = 0, B = 0;
    rep(j, n + 1) {
      if (A == a && B == b) {
        int N = sz(ans);
        if (N == 0) {
          rep(i, n) ans.eb(i + 1);
        } else {
          assert(N >= 3);
          bool g = ans[N - 2] < ans[N - 1];
          while (l <= r) {
            ans.pb(l);
            ++l;
          }
          dbg(g);
          if (g) {
            sort(ans.begin() + N - 1, ans.end());
          } else {
            sort(ans.begin() + N - 1, ans.end(), greater{});
          }
        }
        assert(sz(ans) == n);
        wt(ans);
        return;
      }
      if (j == n) break;
      if (even(i) == even(j)) {
        ans.pb(l++);
      } else {
        ans.pb(r--);
      }
      if (j - 2 >= 0) {
        if (ans[j - 2] < ans[j - 1] && ans[j - 1] > ans[j]) ++A;
        if (ans[j - 2] > ans[j - 1] && ans[j - 1] < ans[j]) ++B;
      }
      dbg(i, ans, l, r, A, B);
    }
  }
  assert(false);
}
