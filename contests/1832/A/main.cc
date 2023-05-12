#include <bits/stdc++.h>

#include "codeforces_multi.h"

bool Solve() {
  strings(s);
  map<int, int> mp;
  each(e, s)++ mp[e];
  if (sz(mp) == 1) return false;
  V<int> v;
  each(_, e, mp) v.eb(e);
  sort(v);
  if (sz(v) == 2 && v[0] == 1) return false;
  return true;
}

void Main() { wt(Solve()); }
