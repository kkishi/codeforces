#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  int sum = accumulate(all(a), int(0));
  int x = 1;
  int i = n - 1;
  int j = 0;
  int ans = 0;
  while (sum > k) {
    if (i == 0) {
      ans += div_ceil(sum - k, n);
      break;
    }
    int y = a[i] - (a[0] - j);
    if (i > 0 && y > x) {
      sum -= y;
      --i;
      ++x;
    } else {
      sum -= x;
      ++j;
    }
    ++ans;
  }
  wt(ans);
}
