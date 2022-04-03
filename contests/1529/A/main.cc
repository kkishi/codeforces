#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int m = *min_element(all(a));
  int ans = 0;
  each(e, a) if (e > m)++ ans;
  wt(ans);
}
