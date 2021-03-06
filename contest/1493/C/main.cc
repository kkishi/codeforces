#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(n, k);
  strings(s);
  dbg(s);
  each(e, s) e -= 'a';

  {
    V<int> cnt(26);
    each(e, s)++ cnt[e];
    bool ok = true;
    each(e, cnt) if (e % k) ok = false;
    if (ok) {
      each(e, s) cout << (char)(e + 'a');
      cout << endl;
      return;
    }
  }

  V<pair<int, int>> ans;
  int ans_i = -1;
  int ans_i_ch;
  int ans_as;
  V<int> cnt(26);
  rep(i, n) {
    // if (s[i] == 25) continue;
    rrep(j, s[i] + 1, 26) {
      cnt[j]++;

      int need = 0;
      V<pair<int, int>> tmp;
      rep(j, 26) if (cnt[j] % k) {
        int x = k - cnt[j] % k;
        need += x;
        tmp.eb(j, x);
      }
      int rem = n - i - 1;
      if (need <= rem && (rem - need) % k == 0) {
        dbg(rem, need);
        dbg(cnt);
        ans = tmp;
        ans_i = i;
        ans_i_ch = j;
        ans_as = rem - need;
        dbg(ans, ans_i, ans_as);
      }
      cnt[j]--;
    }
    cnt[s[i]]++;
  }
  if (ans_i == -1) {
    wt(-1);
    return;
  }
  rep(i, ans_i) cout << (char)(s[i] + 'a');
  cout << (char)(ans_i_ch + 'a');
  rep(ans_as) cout << 'a';
  each(x, y, ans) rep(y) cout << (char)(x + 'a');
  cout << endl;
}

void Main() {
  ints(t);
  rep(t) Solve();
}
