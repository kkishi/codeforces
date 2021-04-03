#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, W);
  V<int> w(n);
  cin >> w;
  sort(all(w), greater{});
  multiset<int> s;
  each(e, w) {
    int x = 0;
    if (!s.empty()) x = *prev(s.end());
    if (e <= x) {
      s.erase(s.find(x));
      s.insert(x - e);
    } else {
      s.insert(W - e);
    }
  }
  wt(sz(s));
}
