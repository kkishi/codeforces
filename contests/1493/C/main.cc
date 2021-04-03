#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  strings(s);
  each(e, s) e -= 'a';

  V<int> cnt(26);
  each(e, s)++ cnt[e];

  {
    bool ok = true;
    each(e, cnt) if (e % k) ok = false;
    if (ok) {
      each(e, s) cout << (char)(e + 'a');
      cout << endl;
      return;
    }
  }

  rrep(i, n) {
    --cnt[s[i]];
    rep(j, s[i] + 1, 26) {
      cnt[j]++;
      int need = 0;
      V<pair<int, int>> added;
      rep(j, 26) if (cnt[j] % k) {
        int x = k - cnt[j] % k;
        need += x;
        added.eb(j, x);
      }
      int rem = n - i - 1;
      if (need <= rem && (rem - need) % k == 0) {
        rep(l, i) cout << (char)(s[l] + 'a');
        cout << (char)(j + 'a');
        rep(rem - need) cout << 'a';
        each(x, y, added) rep(y) cout << (char)(x + 'a');
        cout << endl;
        return;
      }
      cnt[j]--;
    }
  }
  wt(-1);
}
