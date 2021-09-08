#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a), greater{});
  if (a[0] == a[1]) {
    wt(mint::Fact(n));
  } else if (a[0] == a[1] + 1) {
    int cnt = 0;
    each(e, a) if (e == a[1])++ cnt;
    mint ng = mint::Fact(cnt);
    for (int i = cnt + 2; i <= n; ++i) {
      ng *= i;
    }
    wt(mint::Fact(n) - ng);
  } else {
    wt(0);
  }
}
