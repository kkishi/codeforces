#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  ints(m);
  V<int> b(m);
  cin >> b;
  auto f = [](const V<int>& a, const V<int>& b) -> int {
    int A = max(a);
    int B = max(b);
    return A >= B ? 0 : 1;
  };
  wt(f(a, b) == 0 ? "Alice" : "Bob");
  wt(f(b, a) == 0 ? "Bob" : "Alice");
}
