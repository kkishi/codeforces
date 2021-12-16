#include <bits/stdc++.h>

#include "codeforces_interactive.h"

void Main() {
  int t = 1;
  wt_flush(t);
  rep(t) {
    V<int> ans = {0, 0, 0, 1, 0, 1, 1, 1, 1};
    int n = sz(ans);
    assert(n % 3 == 0);
    int zero = 0;
    each(e, ans) if (e == 0)++ zero;
    assert(n / 3 < zero && zero < n * 2 / 3);
    wt_flush(n);
    int queries = 0;
    while (true) {
      rd(char, k);
      if (k == '!') {
        ints(N);
        V<int> ANS(N);
        cin >> ANS;
        V<int> A;
        rep(i, n) if (ans[i] == 0) A.pb(i + 1);
        assert(ANS == A);
        assert(queries <= n + 6);
        return;
      }
      V<int> v(3);
      cin >> v;
      int cnt = 0;
      each(e, v) if (ans[e - 1] == 0)++ cnt;
      wt_flush(cnt >= 2 ? 0 : 1);
      ++queries;
    }
  }
}
