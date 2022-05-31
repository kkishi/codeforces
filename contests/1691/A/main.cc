#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int cnt = 0;
  each(e, a) if (even(e))++ cnt;
  wt(min(cnt, n - cnt));
}
