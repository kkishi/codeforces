#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  V<int> v(4);
  cin >> v;
  int x = max(v[0], v[1]) + max(v[2], v[3]);
  sort(all(v));
  wt(x == v[2] + v[3]);
}
