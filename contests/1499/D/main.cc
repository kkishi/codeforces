#include <bits/stdc++.h>

#include "codeforces_multi.h"

class Sieve {
 public:
  Sieve(i64 n) : v_(n + 1) {
    for (i32 i = 2; i <= n; ++i) {
      if (v_[i] == 0) {
        for (i32 j = i; j <= n; j += i) {
          ++v_[j];
        }
      }
    }
  }
  int UniqueFactors(int n) { return v_[n]; }

 private:
  V<i32> v_;
};

Sieve sieve(20000000);

void Main() {
  ints(c, d, x);
  int ans = 0;
  for (int i = 1; i * i <= x; ++i) {
    auto f = [&](int g) {
      int y = d + g;
      if (y % c == 0) ans += 1LL << sieve.UniqueFactors(y / c);
    };
    if (x % i == 0) {
      f(i);
      if (x / i != i) f(x / i);
    }
  }
  wt(ans);
}
