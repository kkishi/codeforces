#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int mini = *min_element(all(a));
  int ans = 0;
  each(e, a) if (e > mini)++ ans;
  wt(ans);
}
