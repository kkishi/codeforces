#include <bits/stdc++.h>

#include "codeforces_interactive.h"

void Main() {
  int t = 1;
  wt_flush(t);
  rep(t) {
    int n = 6;
    V<int> ans = {0, 0, 0, 1, 1, 1};
    wt_flush(n);
    while (true) {
      rd(char, k);
      if (k == '!') {
        ints(N);
        V<int> ANS(N);
        cin >> ANS;
        V<int> A;
        rep(i, n) if (ans[i] == 0) A.pb(i + 1);
        assert(ANS == A);
        return;
      }
      V<int> v(3);
      cin >> v;
      int cnt = 0;
      each(e, v) if (ans[e - 1] == 0)++ cnt;
      wt_flush(cnt >= 2 ? 0 : 1);
    }
  }
}
