#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, m, k);
  strings(a, b);
  multiset<char> A(all(a)), B(all(b));
  int ac = 0, bc = 0;
  string c;
  while (!A.empty() && !B.empty()) {
    auto a = A.begin();
    auto b = B.begin();
    if (*a > *b) swap(a, b), swap(A, B), swap(ac, bc);
    if (ac == k) {
      c += *b;
      B.erase(b);
      ac = 0;
      bc = 1;
    } else {
      c += *a;
      A.erase(a);
      ++ac;
      bc = 0;
    }
  }
  wt(c);
}
