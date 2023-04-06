#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  strings(s);
  map<int, int> mp;
  each(e, s)++ mp[e];
  V<int> v;
  each(_, e, mp) v.eb(e);
  sort(v);
  if (v == V<int>{4}) {
    wt(-1);
  } else if (v == V<int>{1, 3}) {
    wt(6);
  } else {
    wt(4);
  }
}
