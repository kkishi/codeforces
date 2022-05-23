#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  ints(m);
  V<int> b(m);
  cin >> b;
  int top = 0;
  each(e, b) {
    top += e;
    top %= n;
  }
  wt(a[top]);
}
