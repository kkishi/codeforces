#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  strings(s);
  rep(i, sz(s)) if (s[i] != 'a') {
    wt("YES");
    int j = sz(s) - 1 - i;
    rep(k, sz(s)) {
      cout << s[k];
      if (k == j) cout << 'a';
    }
    cout << endl;
    return;
  }
  wt("NO");
}
