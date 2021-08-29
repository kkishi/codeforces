#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(a, b);
  if (a > b) swap(a, b);
  int n = a + b;
  int A = n / 2, B = n - A;
  set<int> ans;
  rep(2) {
    swap(A, B);
    int aA = min(A, a);
    int aB = a - aA;
    while (true) {
      int bA = A - aA;
      int bB = b - bA;
      ans.insert(aB + bA);
      if (aA == 0 || aB == B) break;
      --aA, ++aB;
    }
  }
  wt(sz(ans));
  wt(vector(all(ans)));
}
