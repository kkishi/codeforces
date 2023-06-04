#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n, q);
  strings(s);
  int sum = 0;
  each(e, s) sum += (e == '(' ? 1 : -1);
  if (!even(sum)) {
    rep(q) wt("NO");
    return;
  }
  s = '.' + s + '.';
  auto isup = [&](int i) { return s[i] == '(' && s[i + 1] == '('; };
  auto isdown = [&](int i) { return s[i] == ')' && s[i + 1] == ')'; };
  set<int> up, down;
  rep(i, 1, n + 1) {
    if (isup(i)) up.insert(i);
    if (isdown(i)) down.insert(i);
  }
  rep(q) {
    ints(i);
    rep(j, i - 1, i + 1) {
      if (isup(j)) up.erase(j);
      if (isdown(j)) down.erase(j);
    }
    s[i] = '(' + ')' - s[i];
    rep(j, i - 1, i + 1) {
      if (isup(j)) up.insert(j);
      if (isdown(j)) down.insert(j);
    }
    auto check = [&]() {
      if (s[1] == ')' || s[n] == '(') return false;
      if (up.empty() != down.empty()) return false;
      if (!up.empty()) {
        if (*up.begin() > *down.begin()) return false;
        if (*prev(up.end()) > *prev(down.end())) return false;
      }
      return true;
    };
    wt(check());
  }
}
